import socket

hostname=socket.gethostname()
port=8050
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(3)
cs,addr=s.accept()

n=int(input("Enter the Number of items : \n"))
li=[]
for i in range(0,n,1):
	temp=int(input("Enter the Element : \n"))
	li.append(temp)

li=str(li)
print("Sending the List to the Client \n")
cs.send(li.encode())
print("The Sorted List is : \n")
data=cs.recv(max)
data=eval(data.decode())
print(data)
