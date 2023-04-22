import socket

hostname=socket.gethostname()
port=8081
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

li=[]
n=int(input("Enter the Size of the List : \n"))
for i in range(0,n):
	temp=int(input("Enter the Element : \n"))
	li.append(temp)
li=str(li)
s.sendto(li.encode(),(hostname,port))
print("Recived Sorted List is : \n")
data,addr=s.recvfrom(max)
data=data.decode()
print(data)