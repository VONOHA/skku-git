import sys
from pwn import *
import time
import re


target = 'tutorial'

context.binary = ELF(target, checksec=False)
context.update(arch='amd64', os='linux')
context.terminal = ['tmux','splitw','-h']

p = process(target)

gdb.attach(p,
           f'''
           b *{overflow}+127
           ''',
           )


io = p
output = io.recv()
print(output.decode('ascii'))

attack_code = b''
############### YOUR INPUT HERE ####################


####################################################


# Send our attack code!
io.sendline(attack_code)

# Get ACCESS GRANTED message!
# output = io.recv(timeout=10)
output = io.interactive()
print(output.decode('ascii'))


# Attack Code


