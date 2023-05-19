prog:audio.o xo.o congrats.o signin.o submenu.o serie.o sauvegarde.o timer.o minimap.o obstacle.o score.o game.o level1.o level2.o level3.o image.o texte.o option.o ennemi.o personne.o scrolling.o menu.o main.o
	gcc audio.o xo.o congrats.o signin.o submenu.o serie.o sauvegarde.o timer.o minimap.o obstacle.o score.o game.o level1.o level2.o level3.o image.o texte.o option.o ennemi.o personne.o scrolling.o menu.o main.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lm -lSDL_mixer -pthread 
main.o:main.c
	gcc -c main.c -g
audio.o:audio.c
	gcc -c audio.c -g
image.o:image.c
	gcc -c image.c -g
texte.o:texte.c
	gcc -c texte.c -g
option.o:option.c
	gcc -c option.c -g
menu.o:menu.c
	gcc -c menu.c -g
level1.o:level1.c
	gcc -c level1.c -g
level2.o:level2.c
	gcc -c level2.c -g
level3.o:level3.c
	gcc -c level3.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
personne.o:personne.c
	gcc -c personne.c -g
scrolling.o:scrolling.c
	gcc -c scrolling.c
game.o:game.c
	gcc -c game.c
score.o:score.c
	gcc -c score.c
obstacle.o:obstacle.c
	gcc -c obstacle.c
timer.o:timer.c
	gcc -c timer.c
minimap.o:minimap.c
	gcc -c minimap.c
sauvegarde.o:sauvegarde.c
	gcc -c sauvegarde.c
serie.o:serie.c
	gcc -c serie.c
submenu.o:submenu.c
	gcc -c submenu.c -g
signin.o:signin.c
	gcc -c signin.c -g
congrats.o:congrats.c
	gcc -c congrats.c -g	
xo.o:xo.c
	gcc -c xo.c -g
	
