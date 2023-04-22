import socket

hostname=socket.gethostname()
port=8050
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print("Connecting to the Server \n")
s.connect((hostname,port))

data=s.recv(max)
li=eval(data.decode())
li.sort()
print("Sending the Sorted List to Server \n")
li=str(li)
s.sendall(li.encode())
