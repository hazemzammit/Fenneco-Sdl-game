#ifndef TEXTE_H 
#define TEXTE_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
}texte;

void initialiser_texte(texte *txte);
void afficher_texte(SDL_Surface *screen, texte txte);
void afficher_texte_op(SDL_Surface *screen, texte txte);
void liberer_texte (texte txte);

#endif


