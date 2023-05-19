#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"




void liberer_image(image imge)
{
    SDL_FreeSurface(imge.img);
}

void liberer_image_double(image_double A)
{
    SDL_FreeSurface(A.img[0]);
    SDL_FreeSurface(A.img[1]);
}


void libererButtons(Button buttons[],int n)
{
    for(int i=0; i<n; i++)
    {
        SDL_FreeSurface(buttons[i].normal.img);
        SDL_FreeSurface(buttons[i].hover.img);
    }
}

void liberer_image_volume(image_volume A)
{
    for(int i=0; i<7; i++)
    {
        SDL_FreeSurface(A.v[i]);
    }
}


int calcul_XBTN(image *imgbtn)
{
    return imgbtn->pos_img.x;
}

int calcul_YBTN(image *imgbtn)
{
    return imgbtn->pos_img.y;
}


void afficher_imageBACK(SDL_Surface *screen,image imge)
{
    SDL_BlitSurface(imge.img, &imge.pos_img, screen, &imge.pos_img);
}

void afficher_imageBTN(SDL_Surface *screen, image imge)
{
    SDL_BlitSurface (imge.img, NULL, screen, &imge.pos_img) ;
}

void afficher_image_double(image_double *A,SDL_Surface * screen)
{
    SDL_BlitSurface (A->img[A->state], NULL,screen,&A->pos_img) ;
}

void afficher_image_volume(image_volume *A,SDL_Surface * screen,int num)
{
    SDL_BlitSurface (A->v[num], NULL,screen,&A->pos_img) ;
}


int calcul_X_IMGD(image_double *A)
{
    return A->pos_img.x;
}

int calcul_Y_IMGD(image_double *A)
{
    return A->pos_img.y;
}



