#ifndef IMAGE_H 
#define IMAGE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_H 480
#define SCREEN_W 640

typedef struct
{
char *url;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran; 
SDL_Surface *img;
}image;

void initialiser_imageBACK(image *imge);


int calcul_XBTN(image *imgbtn);
int calcul_YBTN(image *imgbtn);

void afficher_imageBACK(SDL_Surface *screen, image imge);
void afficher_imageBTN(SDL_Surface *screen, image imge);
void liberer_image(image imge) ;

#endif

