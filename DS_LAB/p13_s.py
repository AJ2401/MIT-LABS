import socket

hostname=socket.gethostname()
port=8091
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((hostname,port))

n=1
while n>0:
	data,addr=s.recvfrom(max)
	if data.decode()=='exit':
		n=0
		break;
	print("Message Recieved : \t"+str(data.decode()))
	temp=input("\nEnter the Message to Send : \n")
	s.sendto(temp.encode(),(addr))