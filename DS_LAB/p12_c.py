import socket

hostname=socket.gethostname()
port=8091
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
temp=input("Enter the String : \n")
s.sendto(temp.encode(),(hostname,port))