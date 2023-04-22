# String send Toggle
import socket

hostname=socket.gethostname()
port=8001
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(3)

cs,addr=s.accept()
data=cs.recv(max)
data=data.decode()

print("String Recived !!\n")
print(data)
l=len(data)
print("Length of the String is : \t"+str(l))
str1=data.swapcase()
print("Sending the Toggled String to the Client \n")
cs.send(str1.encode())
