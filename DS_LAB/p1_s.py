import socket

hostname=socket.gethostname()
port=8080

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(3)

while True:
	sc,addr=s.accept()
	temp=input("Enter the String : \n")
	sc.send(temp.encode())
	