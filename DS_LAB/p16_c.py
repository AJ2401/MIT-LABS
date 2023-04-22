import socket

hostname=socket.gethostname()
port=8088
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

num=int(input("Enter the Number to Send : \n"))
temp=str(num)
s.sendto(temp.encode(),(hostname,port))
data,addr=s.recvfrom(max)
data=data.decode()
print("The Number Modified is : \t"+str(data))