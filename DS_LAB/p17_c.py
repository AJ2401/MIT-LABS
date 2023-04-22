import socket

hostname=socket.gethostname()
port=8080
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

n=1
while n>0:
	temp=input("Enter the Message : \t")
	s.sendto(temp.encode(),(hostname,port))
	data,addr=s.recvfrom(max)
	data=data.decode()
	print("The Encrypted Message is : \t"+str(data))