#ifndef OBSTACLE_H 
#define OBSTACLE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
#include "personne.h"
#include "scrolling.h"



typedef struct
{
SDL_Surface *t[2];
SDL_Rect pos_img;
int current_image;
int collision;
}Objet;


typedef struct
{
Objet o[10];
int nbr_obj;
int score_obj;
}AllObjet;


typedef struct
{
    SDL_Surface *img;
    SDL_Rect pos_img; 
} Obstacle;



typedef struct
{
SDL_Surface *t[5];
SDL_Rect pos_img;
int collision;
}Objet_Door;



void initObjet_trash(Objet *o, int x, int y);
void initObjet_bottle(Objet *o, int x, int y);
void initObjet_melon(Objet *o, int x, int y);
void init_AllObjet_trash(AllObjet *trash);
 void init_AllObjet_melon(AllObjet *melon);
 void init_AllObjet_bottle(AllObjet *bottle);
void afficherObjet(Objet o,SDL_Surface * screen,int num,int scrolling);	
void animerObjet(Objet *o,SDL_Surface * screen,Background Backg);
int collision_Objet(Character c, Objet *o, Background b);

void afficherALLObjets(AllObjet *trash,Character character,SDL_Surface * screen,Background Backg);


 void initObjet_key(Objet *o, int x, int y);
  void init_AllObjet_key(AllObjet *key);

void initObstacle_rocks(Obstacle *o,int num,int x,int y);
void initObstacle_wood(Obstacle *o,int num,int x,int y);
void initObstacle_trcan(Obstacle *o,int num,int x,int y);
void init_AllOobstacle_rocks(Obstacle rocks[]);
void init_AllOobstacle_wood(Obstacle wood[]);
void init_AllOobstacle_trcan(Obstacle trc[]);
void afficherObstacle(Obstacle o, SDL_Surface *screen, int scrolling);

void afficherALLObstacles(Obstacle trc[], SDL_Surface *screen, Background Backg);    


void handle_collision(Character* character, Obstacle* obstacle, Background* background);
void liberer_objet(Objet o);
void liberer_obstacle(Obstacle o);


void initObjet_Door(Objet_Door *o);
void afficherObjet_Door(Objet_Door o, SDL_Surface *screen, int num,int scrolling);
int checkCollision(Character c, Objet_Door* o, Background b);
void updateDoor(Objet_Door *o,Character character, SDL_Surface *screen, Background Backg);



#endif

