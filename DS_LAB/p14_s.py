import socket

hostname=socket.gethostname()
port=8081
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((hostname,port))

data,addr=s.recvfrom(max)
data=data.decode()
li=eval(data)
print("The List Recieved is : \n")
print(li)
li.sort()
print("Sending the Sorted List back !!\n")
li=str(li)
s.sendto(li.encode(),(addr))