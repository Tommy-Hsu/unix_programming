#!/usr/bin/env python3
from pwn import *
import pow as pw
import base64

# start solving here...

def solve_prob():
    
    other = r.recvuntil(b':')
    exp = r.recvuntil(b' = ?').decode()
    exp = exp.replace('= ?', '')    
    # print(exp)
    ans = eval(exp)
    # print(ans)
    little = ans.to_bytes((ans.bit_length() + 7 )//8, byteorder='little') # 不足 0 的地方 前面補 7 個零的概念，除法就會消消 
    # print(little)
    b64 = base64.b64encode(little).decode()
    #print(b64)
    r.sendline(b64.encode())

if __name__=='__main__':

    r = remote('up23.zoolab.org', 10081)
    pw.solve_pow(r)

    #print('************ success to get line ************')
    s1 = r.recvuntil(b'the ')
    s2 = r.recvuntil(b'the ')
    loop = int(r.recvuntil(b' ').decode())
    #print(loop)
    other = r.recvuntil(b'base64')
    

    for x in range(loop):
        solve_prob()

    #rint('************ success to get line ************')
    r.interactive()
    r.close()
    

#r.sendlineafter

#r = process('read Z; echo $Z', shell=True)
#r.sendline(b'AAA')
