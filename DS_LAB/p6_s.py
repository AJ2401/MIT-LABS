import socket

max=1024
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
hostname=socket.gethostname()
port=8082
s.bind((hostname,port))
s.listen(3)

cs,addr=s.accept()

data=cs.recv(max)
print("List is Recived !!\n")
li=data.decode()
l1=eval(li)
print(l1)
n=len(l1)
print("Length of the List is : "+str(n))
for i in range(0,n-1,1):
	for j in range(0,n-1,1):
		if l1[j]>l1[j+1]:
			temp=l1[j]
			l1[j]=l1[j+1]
			l1[j+1]=temp
print("Sending back to Client the Sorted List \n")
l1=str(l1)
cs.send(l1.encode())
