#ifndef ENNEMI_H 
#define ENNEMI_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
#include "personne.h"

typedef struct
{
SDL_Surface *t[2];
SDL_Rect pos_img;
int direction;
int current_image;
}Ennemi;

void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e,SDL_Surface * screen,int num);	
void animerEnnemi(Ennemi *e,SDL_Surface * screen);
void move(Ennemi * e);	
int collisionBB(Character c,Ennemi e);		
void moveIA(Ennemi *e);		

#endif

