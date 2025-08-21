TCC=/c/tcc/tcc
GCC=gcc

all:
	#$(TCC) -Wall -run fixp.c
	$(CC) -Wall -Wextra main.c
	./a.exe

git:
	git commit -am "." ; git push
