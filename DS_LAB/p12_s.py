import socket

hostname=socket.gethostname()
port=8091
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((hostname,port))

data,addr=s.recvfrom(1024)
print("String is : \n"+data.decode())
