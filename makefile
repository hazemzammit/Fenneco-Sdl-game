prog:personne.o main.o
	gcc personne.o  main.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
personne.o:personne.c
	gcc -c personne.c -g
