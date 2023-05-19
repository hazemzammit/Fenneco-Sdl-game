#ifndef SUBMENU_H 
#define SUBMENU_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"



typedef struct {
    image background;
    Button button1;
    Button button2;
} SubMenu;



void submenuL(SDL_Surface *screen);
void submenuS(SDL_Surface *screen);
void initialiser_back_submenu (image *imge);
#endif

