#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "minimap.h"
#include "ennemi.h"
#include "personne.h"
#include "scrolling.h"



void init_minimap(Minimap* minimap, Background* background, Character* character, Ennemi* ennemi,int num)
{
    if (!minimap || !background || !character || !ennemi)
    {
        printf("Error: NULL pointer argument passed to init_minimap\n");
        return;
    }


    minimap->width = 200;
    minimap->height = 100;

    minimap->mapPosition.x = 30;
    minimap->mapPosition.y = 27;

    switch(num)
    {
    case 1:
        minimap->mapImage  = IMG_Load("ressources/background_levels/minimap/city.jpg");
        break;
    case 2:
        minimap->mapImage  = IMG_Load("ressources/background_levels/minimap/beach.jpg");
        break;
    case 3:
        minimap->mapImage  = IMG_Load("ressources/background_levels/minimap/forest.jpg");
        break;

    }


    if (background->BgImg != NULL)
    {
        minimap->characterPosition.x = (character->position.x / background->BgImg->w) * minimap->width ;
        minimap->characterPosition.y = (character->position.y / background->BgImg->h) * minimap->height ;
    }

 
    minimap->ennemiPosition.x = (ennemi->pos_img.x / background->BgImg->w) * minimap->width ;
    minimap->ennemiPosition.y = (ennemi->pos_img.y / background->BgImg->h) * minimap->height ;
}



void blit_minimap(Minimap* minimap, SDL_Surface* screen, Background* background)
{

    int minimap_x = (background->camera.x * minimap->width) / 1366;
    int minimap_y = 0;
    int minimap_w = minimap->width;
    int minimap_h = minimap->height;

    SDL_Rect minimap_rect = {minimap_x, minimap_y, minimap_w, minimap_h};


    SDL_Surface* minimap_portion = SDL_CreateRGBSurface(SDL_SWSURFACE, minimap_w, minimap_h, 32, 0, 0, 0, 0);
    if (minimap_portion == NULL)
    {
        printf("Failed to create minimap portion surface: %s\n", SDL_GetError());
        return;
    }


    if (SDL_BlitSurface(minimap->mapImage, &minimap_rect, minimap_portion, NULL) < 0)
    {
        printf("Failed to blit minimap portion: %s\n", SDL_GetError());
        SDL_FreeSurface(minimap_portion);
        return;
    }


    SDL_Rect characterRect = {minimap->characterPosition.x, minimap->characterPosition.y, 5, 5};
    SDL_FillRect(minimap_portion, &characterRect, SDL_MapRGB(screen->format, 255, 0, 0));

    SDL_Rect ennemiRect = {minimap->ennemiPosition.x, minimap->ennemiPosition.y, 5, 5};
    SDL_FillRect(minimap_portion, &ennemiRect, SDL_MapRGB(screen->format, 0, 0, 255));


    SDL_BlitSurface(minimap_portion, NULL, screen, &minimap->mapPosition);


    SDL_FreeSurface(minimap_portion);
}



void update_minimap_positions(Minimap* minimap, Background* background, Character* character, Ennemi* ennemi)
{
  
    minimap->characterPosition.x = (character->position.x - background->camera.x) / (background->BgImg->w / minimap->width) ;
    minimap->characterPosition.y = (character->position.y - background->camera.y) / (background->BgImg->h / minimap->height) ;

 
    minimap->ennemiPosition.x = (ennemi->pos_img.x - background->camera.x) / (background->BgImg->w / minimap->width) ;
    minimap->ennemiPosition.y = (ennemi->pos_img.y - background->camera.y) / (background->BgImg->h / minimap->height);


}



void initialiser_BackMiniMap(image *A)
{
    A->img=IMG_Load("ressources/progress_bars/fondmap.png");
    A->pos_img.w=236;
    A->pos_img.h=136;
    A->pos_img.x=10;
    A->pos_img.y=10;
}
