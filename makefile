TCC=/c/tcc/tcc
GCC=gcc

all:
	#$(TCC) -Wall -run fixp.c
	$(CC) -O2 -s -Wall -o a.exe fixp.c
	./a.exe

git:
	git commit -am "." ; git push
