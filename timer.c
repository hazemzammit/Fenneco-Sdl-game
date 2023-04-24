#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "timer.h"


void inittime(tim *t){
t->postime.x=0;
t->postime.y=0;
t->police= TTF_OpenFont("Candara.ttf", 18);
t->a.r=0;
t->a.g=255;
t->a.b=0;
time(&(t->t1));
t->s=0;
}


void calcultim(tim *t,SDL_Surface * screen){

time(&(t->t2));
 
t->s=t->t2-t->t1;

sprintf(t->t," %d : %d : %d :",t->s/360,(t->s%360)/60,(t->s%360)%60);
t->ti=  TTF_RenderText_Solid(t->police, t->t, t->a);
SDL_BlitSurface(t->ti, NULL, screen, &t->postime);
SDL_Flip(screen);

}



