import socket
import random
hostname=socket.gethostname()
port=8080
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((hostname,port))

n=1
while n>0:
	data,addr=s.recvfrom(max)
	data=data.decode()
	if data=='exit':
		n=0
		break
	li=list(data)
	l=len(li)
	for i in range(0,l,1):
		if li[i].isupper():
			li[i]=chr(ord(li[i])+int(random.randrange(12,32,2)))
		else:
			li[i]=chr(ord(li[i])-int(random.randrange(12,32,2)))
	temp=''.join(li)
	s.sendto(temp.encode(),addr)
