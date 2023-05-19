#ifndef MENU_H 
#define MENU_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"



void initialiser_back_menu (image *imge);
void initialiser_image_menu(image *imgbtn);
void initButtons(Button buttons[]);
void menu(SDL_Surface *screen);



#endif

