from pwn import *

p = remote('0.0.0.0', 31338)

print(p.recvuntil("production!"))

for i in range(10000000):
	p.sendline("9")
	print(p.recvline().decode("UTF-8"))
	print(p.recvline().decode("UTF-8"))
	#sleep(0.01)
