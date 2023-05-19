#ifndef XO_H_INCLUDED
#define XO_H_INCLUDED
#include <SDL/SDL_image.h>
#include <stdbool.h>
#define CIRCLE 1
#define CROSS -1
#define HAUTEUR_CASE 134
#define LARGEUR_CASE 166
typedef struct
{
   SDL_Surface *Bgimg;
   SDL_Surface *cross;
   SDL_Surface *circle;
   int tabsuivi[9];
   int pos_x;
   int pos_y;
   int joueur;
   int tour; 
   TTF_Font* police;
   SDL_Color color;
   SDL_Rect text_rect;
}tic;

void initialiserTic(tic *t) ;
void afficherTic(tic t, SDL_Surface* screen);
int atilganer(int tabsuivi[]);
void Resultat (int tabsuivi[],SDL_Surface* screen);
int minimax(int tabsuivi[9],int joueur);
void calcul_coup(int tabsuivi [9]);
int xogame(SDL_Surface *screen);

#endif 
