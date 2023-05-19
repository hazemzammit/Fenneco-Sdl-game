#ifndef _TIMER_H_
#define _TIMER_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "image.h"
#include "texte.h"



 typedef struct {
    time_t t1, t2;
    int s;
    char t[100];
    texte text;
} tim;

void init_time(tim* t);
char* calc_time(tim *t);
void blit_time(tim* t, SDL_Surface* screen);

void initialiser_BackTimer(image *A);



#endif
