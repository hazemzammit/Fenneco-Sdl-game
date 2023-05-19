#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



typedef struct {
   
    SDL_Surface* image;
  SDL_Rect position ; 
    int isJumping;
    int isBottom ; 
int velocity ; 
int gravity ; 
} Character;


void character_init(SDL_Surface *screen_surface,Character* character);
void move_right(Character* character);
void afficher_perso(SDL_Surface* screen_surface,Character character);
void move_left(Character* character);
void character_jump(Character* character);
void update_pos(Character* character) ; 
void animerperso(Character* character,SDL_Surface *screen,int  currentDirection,int animationFlip);

#endif // PERSONNE_H_INCLUDED


