prog: main.o scrolling.o anim.o 
	gcc  main.o scrolling.o anim.o -o prog -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c

scrolling.o:scrolling.c
	gcc -c scrolling.c
anim.o:anim.c
	gcc -c anim.c
