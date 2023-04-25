#ifndef ANIMM_H 
#define ANIMM_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct
{
SDL_Surface *t[2];
SDL_Rect pos_img;
int current_image;
}anim;

void initanimm(anim *a);
void afficheranimm(anim a,SDL_Surface * screen,int num);	
void animer(anim *a,SDL_Surface * screen);

#endif
