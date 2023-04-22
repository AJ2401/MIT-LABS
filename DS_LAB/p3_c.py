import socket

hostname=socket.gethostname()
port=8077
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
max=1024
print("Connecting to the Server !!\n")
s.connect((hostname,port))
n=1
while n>0:
	data=s.recv(max)
	print("The Data Recieved is : \n"+str(data.decode()))
	print("Server Side Message : \n")
	temp=input("Enter the Client Message : \n")
	if temp=="exit":
		s.sendall(temp.encode())
		break
	else:s.sendall(temp.encode())