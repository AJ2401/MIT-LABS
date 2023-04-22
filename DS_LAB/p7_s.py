# list exchange sort
import socket

hostname=socket.gethostname()
port=8087
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(3)

cs,addr=s.accept()
data=cs.recv(max)
data=data.decode()
li=eval(data)
print("Recived LIST is : \n")
print(li)

n=len(li)
for i in range(0,n-1,1):
	for j in range(0,n-1,1):
		if li[j]>li[j+1]:
			temp=li[j]
			li[j]=li[j+1]
			li[j+1]=temp
print("Sending the Sorted List to Client : \n")
li=str(li)
cs.send(li.encode())
