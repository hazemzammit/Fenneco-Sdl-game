#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "texte.h"

void initialiser_texte (texte *txte)
{
TTF_Init();
txte->police = TTF_OpenFont ("ressources/font/Ubuntu-B.ttf", 45);
txte->color_txt.r=255;
txte->color_txt.g=255;
txte->color_txt.b=255;
txte->pos_txt.x=1366/2-100;
txte->pos_txt.y=70;
}

void afficher_texte (SDL_Surface *screen, texte txte)
{
txte.txt=TTF_RenderText_Blended(txte.police, "FENNECO", txte.color_txt);
SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
}

void afficher_texte_op (SDL_Surface *screen, texte txte)
{
txte.txt=TTF_RenderText_Blended(txte.police, "Options", txte.color_txt);
SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
}

void liberer_texte (texte txte)
{
TTF_CloseFont (txte.police);
TTF_Quit ();
}





