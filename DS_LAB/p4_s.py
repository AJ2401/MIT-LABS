import socket

hostname=socket.gethostname()
port=12345
max=1024
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(3)

cs,addr=s.accept()
n=int(input("Enter the Number of Elements : \n"))
li=[]
for i in range(0,n,1):
	temp=int(input("Enter the Element : \n"))
	li.append(temp)
print("The List is : \n"+str(li))
list=str(li)
list=list.encode()
cs.send(list)
data=cs.recv(max)
print("The Sorted List is : \n"+str(data.decode()))

