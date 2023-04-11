#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"

void initialiser_imageBACK (image *imge)
{
imge->url="background.jpg";
imge->img=IMG_Load(imge->url);
if (imge->img == NULL) {
printf("unable to load background image %s\n", SDL_GetError());
return;}
imge->pos_img_ecran.x=0;
imge->pos_img_ecran.y=0;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0;
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;
}


void afficher_imageBACK(SDL_Surface *screen,image imge)
{
SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}



void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}

