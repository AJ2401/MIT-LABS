import socket

hostname=socket.gethostname()
port=8084
max=1024

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((hostname,port))
s.listen(3)
cs,addr=s.accept()

n=1
while n>0:
	data=cs.recv(max)
	data=data.decode()
	if data=='exit':
		n=0
		break
	else:

		l=len(data)
		temp = list(data)
		
		for i in range(l):
			temp[i] = chr(ord(temp[i])+33)
		t1 = ''.join(temp)
		print(data, temp, t1)
		cs.send(t1.encode())


