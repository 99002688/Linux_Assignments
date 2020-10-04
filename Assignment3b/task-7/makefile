
all: rm my client server

rm:
	rm -rf *.out *.o MYFIFO
my:
	mkfifo MYFIFO

client:
	gcc client.c -o c.out

server:
	gcc server.c -o s.out
