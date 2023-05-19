#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "timer.h"
#include <time.h>
#include "image.h"


void init_time(tim* t) {
    t->text.pos_txt.x=335;
    t->text.pos_txt.y=26;
    t->text.police =  TTF_OpenFont("ressources/font/Candara.ttf", 18);
    t->text.color_txt.r=255;
     t->text.color_txt.g=255;
      t->text.color_txt.b=255;
    time(&(t->t1));
    t->s = 0;
}


char* calc_time(tim *t) {
    time(&(t->t2));
    int elapsed = t->t2 - t->t1;
    sprintf(t->t, " %02d:%02d:%02d", elapsed / 360, (elapsed % 360) / 60, (elapsed % 360) % 60);
    return t->t;
}

void blit_time(tim *t, SDL_Surface *screen) {
    t->text.txt = TTF_RenderText_Solid(t->text.police, calc_time(t), t->text.color_txt);
    SDL_BlitSurface(t->text.txt, NULL, screen, &t->text.pos_txt);
    SDL_FreeSurface(t->text.txt);
}



void initialiser_BackTimer(image *A)
{
    A->img=IMG_Load("ressources/progress_bars/time.png");
    A->pos_img.w=159;
    A->pos_img.h=47;
    A->pos_img.x=270;
    A->pos_img.y=12;
}

