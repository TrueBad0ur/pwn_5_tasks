#!/bin/python

from pwn import *

p = remote('0.0.0.0', 31341)
#p = process("./task")
letters = []

p.recvuntil("Your main function is here: ")
main_f = int(int(p.recvuntil("\n")[:-1].decode("UTF-8"), 16))
functions_array = [main_f - 2013, main_f - 1586, main_f - 1464, main_f - 1220, main_f - 854, main_f - 732, main_f - 488, main_f - 366, main_f - 183, main_f - 61, main_f - 122, main_f - 549, main_f - 671, main_f - 793, main_f - 1159, main_f - 1037, main_f - 1098, main_f - 976, main_f - 915, main_f - 1281, main_f - 1403, main_f - 1525, main_f - 1647, main_f - 1830, main_f - 1769, main_f - 1952, main_f - 1891, main_f - 1708, main_f - 1342, main_f - 610, main_f - 427, main_f - 244, main_f - 305]

p.recvuntil("Enter func addr: ")

for i in range(len(functions_array)):
	p.sendline(str(functions_array[i]))
	p.recvline()
	letters.append(p.recvline()[:-1].decode("UTF-8"))
	p.recvline()

print(''.join(letters))

p.interactive()
