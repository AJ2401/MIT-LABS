import socket
import random

max=1024
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
hostname=socket.gethostname()
port=8082
s.connect((hostname,port))

n=int(input("Enter the Number of Items : \n"))
li=[]

for i in range(0,n,1):
	temp=int(input("Enter the Item : \n"))
	li.append(temp)

# li=random.shuffle(li)
li=str(li)
print("Sending the List to Server !\n")
s.sendall(li.encode())
print("Sorted List Recieved \n")
data=s.recv(max)
data=data.decode()
li=eval(data)
print(li)


