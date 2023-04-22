import socket

hostname=socket.gethostname()
port=1232
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(3)

while True:
	cs,addr=s.accept()
	temp=input("Enter the String to Send !!\n")
	cs.send(temp.encode())
	data=cs.recv(max)
	print("The String Recieved From Client is : \n"+str(data.decode()))