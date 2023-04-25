#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "anim.h"

void initEnnemi(Ennemi *e)
{
e->t[0]=IMG_Load("e0.png");
e->t[1]=IMG_Load("e1.png");
e->pos_img.x=350;
e->pos_img.y=350;
e->pos_img.w=123;
e->pos_img.h=101;
e->direction=1;
e->current_image=0;
}


void afficherEnnemi(Ennemi e,SDL_Surface * screen,int num)
{
	SDL_BlitSurface (e.t[num], NULL,screen,&e.pos_img) ;
}


void animerEnnemi(Ennemi *e, SDL_Surface *screen)
{
    static int frame_counter = 0;
    frame_counter++;
    if (frame_counter >= 50) {
        if (e->current_image == 0) {
            e->current_image = 1;
        } else {
            e->current_image = 0;
        }
        frame_counter = 0;
    }
	afficherEnnemi(*e,screen,e->current_image);
	SDL_Flip(screen);
}









