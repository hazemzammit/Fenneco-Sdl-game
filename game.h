#ifndef GAME_H 
#define GAME_H
#include <SDL/SDL.h>

typedef struct Game {
    int num_level;
    char username[99];
} Game;

typedef struct Score Score;


typedef struct
{
SDL_Surface *t[3];
SDL_Rect pos_img;
}image_level;


void game(SDL_Surface *screen,int isNew,int numLevel );
void GetGameInfo(Game* g,int num);
void updateGame(Game* g,int levelState,SDL_Surface *screen, Score* s);


void initialiser_imageLevels(image_level *A);
void afficherimgLevel(image_level A,SDL_Surface *screen,int num);

#endif

