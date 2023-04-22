import socket

hostname=socket.gethostname()
port=8092
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((hostname,port))

data,addr=s.recvfrom(max)
data=data.decode()
l=len(data)
li=list(data)

for i in range(0,l,1):
	if li[i]>'a' and li[i]<'z':
		li[i]=chr(ord(li[i])-33)
	elif li[i]>'A' and li[i]<'Z':
		li[i]=chr(ord(li[i])+33)
l1=''.join(li)
# str(l1)
s.sendto(l1.encode(),addr)

