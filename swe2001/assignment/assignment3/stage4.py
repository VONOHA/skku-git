import sys
from pwn import process, context, p64, ELF
import time
import re

target = './stage4'
context.binary = ELF(target, checksec=False)


p = process(target)
io = p

# Receive output from program and print it in ASCII
output = io.recv()
print(output.decode('ascii'))

############### YOUR INPUT HERE ####################


####################################################

# Send input to program
io.sendline(input)

# Get output
output = io.recv()
print(output.decode('ascii'))







