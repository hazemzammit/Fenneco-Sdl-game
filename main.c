#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "personne.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define DIR_LEFT         3
#define DIR_RIGHT       1
#define SPRITE_SIZE     32


int main(int argc, char* argv[]) {
    SDL_Surface* screen_surface;

   int quit=0 ; 
  
    int currentDirection = DIR_RIGHT;

    int animationFlip = 0;
    Character character;
image IMAGElevel ;
    SDL_Event event;
     // initialize SDL video
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // create a window
    screen_surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
    if (screen_surface == NULL) {
        fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
        return 1;
    }
 initialiser_imageBACK (&IMAGElevel) ; 
    /* set keyboard repeat */


 character_init(screen_surface,&character) ;  

 

    // main loop

  int velocity = 0;
while (!quit) {
    afficher_imageBACK(screen_surface, IMAGElevel);
 

    // handle events
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quit = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
   SDL_EnableKeyRepeat(10, 10);
                        character_jump(&character);
                        break;
                    case SDLK_RIGHT:
    
                        move_right(&character);
  currentDirection = DIR_RIGHT;
                    animationFlip = 1 - animationFlip;
                        break;
                    case SDLK_LEFT:
 
                        move_left(&character);
  currentDirection = DIR_LEFT;
                    animationFlip= 1 - animationFlip;
                        break;
                }
                break;
        }
    }
animerperso(&character,screen_surface, currentDirection, animationFlip) ; 

    // update character position
update_pos(&character) ; 

    // draw character
    SDL_Flip(screen_surface);
}




    // free character surface
 liberer_image( character) ;

    // quit SDL
    SDL_Quit();

    return 0;
}
