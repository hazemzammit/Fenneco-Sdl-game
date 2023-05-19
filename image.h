#ifndef IMAGE_H 
#define IMAGE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_H 665
#define SCREEN_W 1366

typedef struct
{
SDL_Rect pos_img;
SDL_Surface *img;
}image;

typedef struct
{
SDL_Surface *img[2];
SDL_Rect pos_img;
int state;
}image_double;

typedef struct
{
SDL_Surface *v[7];
SDL_Rect pos_img;
}image_volume;


typedef struct {
    image normal;  
    image hover;
    int state;   
} Button;


typedef struct
{
    SDL_Surface **t; // pointer to an array of SDL surfaces
    int num_images; // number of images in the array
    SDL_Rect pos_img;
} image_Intro;

void initialiser_imageBACK_jouer (image *imge);

int calcul_XBTN(image *imgbtn);
int calcul_YBTN(image *imgbtn);
int calcul_X_IMGD(image_double *A);
int calcul_Y_IMGD(image_double *A);

void afficher_imageBACK(SDL_Surface *screen, image imge);
void afficher_imageBTN(SDL_Surface *screen, image imge);
void afficher_image_double(image_double *A,SDL_Surface * screen);
void afficher_image_volume(image_volume *A,SDL_Surface * screen,int num);



void liberer_image(image imge);
void liberer_image_double(image_double A);
void liberer_image_volume(image_volume A);
void libererButtons(Button buttons[],int n);

#endif

