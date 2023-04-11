#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct {
    SDL_Surface* image;
    SDL_Rect position ; 
    int dx;
    int dy;
    int jumping;
} Character;

void character_init(Character* character, const char* image_path, int x, int y);
void move_right(Character* character);
void afficher_perso(SDL_Surface* screen_surface,Character character);
void move_left(Character* character);
void character_jump(Character* character);

#endif 


