import socket

hostname=socket.gethostname()
port=8090
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(2)
cs,addr=s.accept()

data=cs.recv(max)
data=data.decode()
print("Recieved String .. \t"+str(data))
li=list(data)
n=len(li)
for i in range(0,n,1):
	if li[i].isupper():
		li[i]=chr(ord(li[i])+33)
	else:
		li[i]=chr(ord(li[i])-33)
t=''.join(li)
data=str(t)
print("Sending Encrypted String .. \n")
cs.send(data.encode())
