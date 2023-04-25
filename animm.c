#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animm.h"

void initanimm(anim *a)
{
a->t[0]=IMG_Load("of.bmp");
a->t[1]=IMG_Load("oo.bmp");
a->pos_img.x=50;
a->pos_img.y=50;
a->pos_img.w=100;
a->pos_img.h=100;
a->current_image=0;
}


void afficheranimm(anim a,SDL_Surface * screen,int num)
{
	SDL_BlitSurface (a.t[num], NULL,screen,&a.pos_img) ;
}


void animer(anim *a, SDL_Surface *screen)
{
    static int frame_counter = 0;
    frame_counter++;
    if (frame_counter >= 50) {
        if (a->current_image == 0) {
            a->current_image = 1;
        } else {
            a->current_image = 0;
        }
        frame_counter = 0;
    }
	afficheranimm(*a,screen,a->current_image);
	SDL_Flip(screen);
}
