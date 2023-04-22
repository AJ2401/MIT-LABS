import socket

hostname=socket.gethostname()
port=8090
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((hostname,port))

temp=input("Enter the String : \n")
print("Sending the String ..\n")
s.send(temp.encode())
data=s.recv(max)
data=data.decode()
print("The Encrypted String is : \n"+str(data))