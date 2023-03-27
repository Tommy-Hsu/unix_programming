from pwn import *
elf = ELF('./chals')
print("main =", hex(elf.symbols['main']))
print("{:<12s} {:<8s} {:<8s}".format("Func", "GOT Offset", "Symbol Offset"))
for g in elf.got:
   if "code_" in g:
      #print("{:4d}".format(int(g.replace("code_",""))), end=", ")
      #print("\"{:<8x}\"".format(elf.got[g]), end=", ")
       print("\"{:<8x}\"".format(elf.symbols[g]), end=", ")