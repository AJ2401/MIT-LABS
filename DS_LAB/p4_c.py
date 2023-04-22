import socket

hostname=socket.gethostname()
port=12345
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((hostname,port))
max=1024
data=s.recv(max)
print("The List is : \n"+str(data.decode()))
data=data.decode()
li=eval(data)
li.sort()
data1=str(li)
print("Sending Sorted LIST \n")
s.sendall(data1.encode())
