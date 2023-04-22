import socket

hostname=socket.gethostname()
port=8084
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((hostname,port))

n=1
while n>0:
	temp=input("Enter the String : \n")
	if temp=='exit':
		s.send(temp.encode())
		n=0
		break
	else:
		s.send(temp.encode())
		data=s.recv(max)
		data=data.decode()
		print("The ENCRYPTED STRING IS :\n")
		print(data)