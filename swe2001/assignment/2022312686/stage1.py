from pwn import *
import time
import re

# target = './build/stage1'
target = './stage1'
context.binary = ELF(target, checksec=False)


p = process(target)
io = p



output = io.recv()
print(output.decode('ascii'))

############### YOUR INPUT HERE ####################
input = 'a'*  16

####################################################

# Send input to program
io.sendline(input)

# Get output
output = io.recv()
print(output.decode('ascii'))
