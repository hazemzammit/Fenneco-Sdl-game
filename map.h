#ifndef map_H_INCLUDED
#define map_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdbool.h>



typedef struct
{
   
    SDL_Rect PositionBg;   
    SDL_Surface *Bgimg; 
    
} minimap;

void initmap(minimap*min);
void freebackground(minimap *min);
void blitting(SDL_Surface *screen,minimap *min);


#endif


