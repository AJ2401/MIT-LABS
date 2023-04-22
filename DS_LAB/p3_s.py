import socket

hostname=socket.gethostname()
port=8077
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
max=1024
s.bind((hostname,port))
s.listen(3)
n=1

cs,addr=s.accept()
while n>0:
	temp=input("Send to Reciver : \n")
	cs.send(temp.encode())
	data=cs.recv(max)
	if data.decode() == "exit": n=0
	print("Reciever Message : \n"+str(data.decode()))