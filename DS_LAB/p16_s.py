import socket
import random

hostname=socket.gethostname()
port=8088
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((hostname,port))

data,addr=s.recvfrom(max)
print("The Number is : \t"+str(data.decode()))
num=eval(data.decode())
num=num+random.randrange(10,100,2)
num=str(num)
s.sendto(num.encode(),addr)

