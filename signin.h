#ifndef SIGNIN_H 
#define SIGNIN_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"



typedef struct {
    image background;
    Button button1;
    Button button2;
} SignIn;



char* Getusername();
void signin(SDL_Surface *screen);

#endif

