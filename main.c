#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "map.h"
#include "timer.h"
#include "animm.h"
#include "personne.h"
#include "ennemi.h"


int main()
{
    Character character;
    Ennemi e;
    anim a;
    tim timer;
    minimap mini;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Event event;
    SDL_Surface *screen=NULL;
    SDL_Rect camera;
    screen = SDL_SetVideoMode(1080,750, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(screen==NULL)
    {
      printf("unable to set video mode: %s /n",SDL_GetError());
    }
    
    int running = 1;
    int collision;
    int direction;
    initmap(&mini);
    inittime(&timer);
    initanimm(&a);
    initEnnemi(&e);
    character_init(&character, "perso.png", 0, 1080 - 100);
    character.dx = 5;
    int i=0;
    while(running) {

	
        while(SDL_PollEvent(&event)) {
       
          
          switch(event.type) {
                

                                       case SDL_KEYDOWN:
					if(event.key.keysym.sym ==SDLK_ESCAPE)
					{
						running=0;
					}
					
					if(event.key.keysym.sym ==SDLK_SPACE)
					{
						 character_jump(&character);
					}
					
					if(event.key.keysym.sym ==SDLK_RIGHT)
					{
						move_right(&character);
					}
					
					if(event.key.keysym.sym ==SDLK_LEFT)
					{
						move_left(&character);
					}
					
				break;
				

				case SDL_QUIT: 
					running=0;
				break;
			}		
            
        
        }
        
        blitting(screen,&mini);
        afficher_perso(screen,character); 
        animerEnnemi(&e,screen);
	move(&e);
        collision=collisionBB(character,e);
		if(collision==1)
		{
			printf("Collision \n");
		}
      
        calcultim(&timer,screen);
        animer(&a,screen);
        SDL_Flip(screen); 
        SDL_Delay(50);
    }
   SDL_FreeSurface(e.t[0]);
   SDL_FreeSurface(e.t[1]);
   SDL_FreeSurface(a.t[0]);
   SDL_FreeSurface(a.t[1]);
   freebackground(&mini);
    SDL_Quit();
    return 0;
}

      
