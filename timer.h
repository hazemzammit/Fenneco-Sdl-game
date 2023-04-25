#ifndef _TIMER_H_
#define _TIMER_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>





typedef struct{
SDL_Rect postime;
SDL_Surface * ti;
time_t t1,t2;
SDL_Color a;
TTF_Font *police;
int s;
char t[100];
}tim;


void inittime(tim *t);
void calcultim(tim *t,SDL_Surface * screen);
void calcultimenig(tim *t,SDL_Surface * screen);
#endif
