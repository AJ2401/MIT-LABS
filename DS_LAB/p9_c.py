import socket

hostname=socket.gethostname()
port=8900
max=100

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((hostname,port))

n=1
while n>0:
	temp=input("Enter the Message : \n")
	if temp=='exit':
		n=0
		s.send(temp.encode())
		break
	else:
		s.send(temp.encode())
		print("\tMESSAGE RECIEVED : \n")
		data=s.recv(max)
		data=data.decode()
		print("\t"+data)