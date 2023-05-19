#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "audio.h"
#include "image.h"
#include "texte.h"
#include "menu.h"


int main()
{
	SDL_Surface *screen;
	image_Intro A;

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
	{
		printf("Erreur Initialisation SDL %s .\n",SDL_GetError());
		return -1;
	}
	
	screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
	SDL_WM_SetCaption("FENNECO", NULL);


	menu(screen);
	

	return 0;
}






	




