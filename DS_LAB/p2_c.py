import socket

hostname=socket.gethostname()
port=1232
max=1024
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((hostname,port))

data=s.recv(max)
print("The String Recieved from Server is : \n"+str(data.decode()))
temp=input("Enter the String to Send to Server : \n")
s.sendall(temp.encode())
