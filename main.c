#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "scrolling.h"
#include "anim.h"
int main()
{
    Ennemi e;
    Background Backg;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *screen=NULL;

    screen = SDL_SetVideoMode(1080,671, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(screen==NULL)
    {
      printf("unable to set video mode: %s /n",SDL_GetError());
    }

    bool running = true;
    const int FPS = 30;
    const int speed = 5;
    Uint32 start;
    int direction;
    

    initBackground(&Backg);
    initEnnemi(&e);


    bool b[4] = {0,0,0,0};
    while(running) {
        start = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP :
                            b[2]=1;
                            break;
                        case SDLK_RIGHT:
                            b[0] = 1;
                            break;
                        case SDLK_LEFT:
                            b[1] = 1;
                            break;
                        case SDLK_DOWN:
                            b[3]=1;
                            break;
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                    }
                    break;

                case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP :
                            b[2]=0;
                            break;
                        case SDLK_RIGHT:
                            b[0] = 0;
                            break;
                        case SDLK_LEFT:
                            b[1] = 0;
                            break;
                        case SDLK_DOWN:
                            b[3]=0;
                            break;

                    }
                    break;
            }

        }
	
        scrolling(&Backg,b);
        blitting(&Backg,screen);
	animerEnnemi(&e,screen);
        

        

        SDL_Flip(screen);
        if(1000/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
    }
    SDL_FreeSurface(e.t[0]);
    SDL_FreeSurface(e.t[1]);
    freeBackground(&Backg);
    SDL_Quit();
    return 0;
}
