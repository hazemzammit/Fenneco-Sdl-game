prog:ennemi.o image.o personne.o main.o
	gcc ennemi.o image.o personne.o main.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
image.o:image.c
	gcc -c image.c -g
personne.o:personne.c
	gcc -c personne.c -g
