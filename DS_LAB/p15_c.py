import socket

hostname=socket.gethostname()
port=8092
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

temp=input("Enter the String : \n")
s.sendto(temp.encode(),(hostname,port))
data,addr=s.recvfrom(max)
print("The Encrypted String is : \t"+str(data.decode()))
