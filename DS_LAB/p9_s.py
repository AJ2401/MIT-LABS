#chat server-client

import socket

hostname=socket.gethostname()
port=8900
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(3)

n=1
cs,addr=s.accept()
while n>0:
	data=cs.recv(max)
	data=data.decode()
	if data =='exit':
		n=0
	else:
		print("\tMESSAGE RECIEVED : \n")
		print("\t"+data)
		temp=input("\nEnter your Message : \n")
		cs.send(temp.encode())

