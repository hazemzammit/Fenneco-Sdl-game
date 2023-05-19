#ifndef ENNEMI_H 
#define ENNEMI_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
#include "personne.h"
#include "scrolling.h"

typedef enum STATE STATE;
enum STATE {WAITING,FOLLOWING,ATTACKING,DEAD};

typedef struct
{
SDL_Surface *t[9];
SDL_Rect pos_img;
int direction;
int current_image;
int collision;
STATE state;
}Ennemi;



void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e,SDL_Surface * screen,int num,int scrolling);	
void animerEnnemi_waiting(Ennemi *e,SDL_Surface * screen,Background Backg);
void animerEnnemi_following(Ennemi *e, SDL_Surface *screen,Background Backg);
void animerEnnemi_attacking(Ennemi *e, SDL_Surface *screen,Background Backg);
void move(Ennemi * e);	
void collisionBB(Character *c, Ennemi *e, Background Backg);
void moveIA(Ennemi *e);		

int distance(Ennemi e, Character c);
void updateEnnemiState (Ennemi* e, int dist);
void updateEnnemi(Ennemi* e,Character *character, SDL_Surface* screen,Background Backg);



void liberer_ennemi(Ennemi e);


#endif

