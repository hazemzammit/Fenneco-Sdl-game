#ifndef MINIMAP_H_INCLUDED
#define MINIMAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>

#include "ennemi.h"
#include "personne.h"
#include "scrolling.h"
#include "image.h"

typedef struct {
    SDL_Surface* mapImage;
    SDL_Rect mapPosition;
    SDL_Rect characterPosition;
    SDL_Rect ennemiPosition;
    int width; // Add width member
    int height; // Add height member
} Minimap;

void init_minimap(Minimap* minimap, Background* background, Character* character, Ennemi* ennemi,int num);
void blit_minimap(Minimap* minimap, SDL_Surface* screen, Background* background) ;
void initialiser_BackMiniMap(image *A);

void update_minimap_positions(Minimap* minimap, Background* background, Character* character, Ennemi* ennemi);

#endif
