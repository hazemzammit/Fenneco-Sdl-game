#ifndef OPTION_H 
#define OPTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>




void initialiser_BACK_settings (image *imge);
void initialiser_image_settings(image *imgbtn);
void initialiser_return(image_double *img);
void initialiser_plus(image_double *A);
void initialiser_moins(image_double *A);
void initialiser_mute_unmute(Button BTM[]);
void initialiser_normal_full(Button BTF[]);
void initialiser_volume(image_volume *A);

void option(SDL_Surface *screen);


#endif

