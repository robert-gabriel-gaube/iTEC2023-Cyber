from pwn import *

data = [10, 21, 22, 22, 19, 1, 13, 7, 9]
input = [7,23,23,10,20,20,25,25,4,11,1,3,17,21,16,5,23,24,19,21,8,9,15,17,0,24,10,23,11,0,9,1,18,4,18,21,0,0,15,19,9,6,15,9,11,10,20,0,9,21,12,21,15,19,15,11,4,9,23,25,22,2,1,19,9,8,15,11,19,19,23,3,7,15,19]

r = remote('64.226.75.15', 60002)

r.recvuntil("\n    .-----------.\n    |           |\n    |         O |\n    | SCRISOARE |\n    |  PIERDUTA |\n    |           |\n    |     I.L.C |\n    .___________.\n    \n Introduceti mesajul:")

new_input = ""
for e in input:
    new_input = new_input + chr(e + ord('a'))

print(new_input)

r.send(new_input + "\n")

r.recvuntil(" Introduceti cheia:")

new_data = ""

for e in data:
    new_data = new_data + chr(e + ord('a'))

r.send(new_data + "\n")
x = r.recvline()
print(x)

