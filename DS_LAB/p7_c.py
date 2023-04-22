import socket

hostname=socket.gethostname()
port=8087
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((hostname,port))
print("Connected To Server !!\n\n")

li=[]
n=int(input("Enter the number of Element in the List : \n"))

for i in range(0,n,1):
	temp=int(input("Enter the data item : \t"))
	li.append(temp)
print("Sending the List to Server ..\n")
li=str(li)
s.sendall(li.encode())

data=s.recv(max)
data=data.decode()
li1=eval(data)
print("The Sorted List is :\n")
print(li1)
