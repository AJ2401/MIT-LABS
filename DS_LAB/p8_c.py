import socket

hostname=socket.gethostname()
port=8001
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((hostname,port))

print("Connected to the Server !!\n")
temp=input("Enter the String : \n")
s.sendall(temp.encode())
print("The toggled String is : \n")
data=s.recv(max)
data=data.decode()
print(data)
