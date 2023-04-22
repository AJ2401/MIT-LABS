import socket

hostname=socket.gethostname()
port=8091
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

n=1
while n>0:
	temp=input("Enter the String to Send : \n")
	if temp=='exit':
		s.sendto(temp.encode(),(hostname,port))
		n=1
		break
	else:
		s.sendto(temp.encode(),(hostname,port))
	data,addr=s.recvfrom(max)
	data=data.decode()
	print("The Message Recived is : \t"+str(data))

