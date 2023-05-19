#ifndef ENNEMI_H 
#define ENNEMI_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "personne.h"
#include "scrolling.h"

typedef enum STATE STATE;
enum STATE {WAITING,FOLLOWING,ATTACKING,DEAD};

/**
* @struct Ennemi
* @brief struct for Ennemi
*/

typedef struct
{
SDL_Surface *t[9];    /*!< Images*/
SDL_Rect pos_img;    /*!< Position*/
int direction;	 /*!< Ennemiy direction*/
int current_image;   /*!< The current image*/
int collision;     /*!< There is collision or not*/
STATE state;  /*!< Ennemy state */
}Ennemi;

/**
* @struct Objet
* @brief struct for Ennemi
*/

typedef struct
{
SDL_Surface *t[2];  /*!< Images*/
SDL_Rect pos_img;   /*!< Position*/
int current_image;    /*!< The current image*/
int collision;  /*!< There is collision or not*/
}Objet;


/**
* @struct Obstacle
* @brief struct for Ennemi
*/
typedef struct
{
    SDL_Surface *t[3];  /*!< Images*/
    SDL_Rect pos_img[3];  /*!< Position*/
    int current_image;    /*!< The current image*/
} Obstacle;


void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e,SDL_Surface * screen,int num,int scrolling);	
void animerEnnemi_waiting(Ennemi *e,SDL_Surface * screen,Background Backg);
void animerEnnemi_following(Ennemi *e, SDL_Surface *screen,Background Backg);
void animerEnnemi_attacking(Ennemi *e, SDL_Surface *screen,Background Backg);
void move(Ennemi * e);	
void collisionBB(Character c,Ennemi *e);		
void moveIA(Ennemi *e);		

int distance(Ennemi e, Character c);
void updateEnnemiState (Ennemi* e, int dist);

void initObjet_bottle(Objet *o);
void initObjet_trash(Objet *o);
void initObjet_melon(Objet *o);
void afficherObjet(Objet o,SDL_Surface * screen,int num,int scrolling);	
void animerObjet(Objet *o,SDL_Surface * screen,Background Backg);
void collision_Objet(Character c,Objet *o);		


void initObstacle_rocks(Obstacle *o);
void initObstacle_wood(Obstacle *o);
void initObstacle_trcan(Obstacle *o);
void afficherObstacle(Obstacle o, SDL_Surface *screen, int num, int scrolling);


void handle_collision(Character* character, Obstacle* obstacle) ;


#endif

