import socket

hostname=socket.gethostname()
port=8080
size =1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.connect((hostname,port))
print("The Client is Connected to the Server !\n")

while True:
	temp=s.recv(size)
	print("Message Recieved is : \n"+str(temp.decode()))
