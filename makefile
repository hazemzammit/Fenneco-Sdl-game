prog:ennemi.o personne.o scrolling.o main.o
	gcc ennemi.o personne.o main.o scrolling.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer -lm
main.o:main.c
	gcc -c main.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
personne.o:personne.c
	gcc -c personne.c -g
scrolling.o:scrolling.c
	gcc -c scrolling.c
