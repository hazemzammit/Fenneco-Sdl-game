#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "image.h"
#include "audio.h"
#include "option.h"


void initialiser_BACK_settings (image *imge)
{
    imge->img=IMG_Load("ressources/images/settings/back_settings.png");
    imge->pos_img.x=0;
    imge->pos_img.y=0;
    imge->pos_img.h=SCREEN_H;
    imge->pos_img.w=SCREEN_W;
}

void initialiser_image_settings(image *imgbtn)
{
    imgbtn->img=IMG_Load("ressources/images/settings/settings_menu.png");
    imgbtn->pos_img.w=709;
    imgbtn->pos_img.h=485;
    imgbtn->pos_img.x=(SCREEN_W-imgbtn->pos_img.w)/2;
    imgbtn->pos_img.y=((SCREEN_H-imgbtn->pos_img.h)/2);
}

void initialiser_moins(image_double *A)
{
    A->img[0]=IMG_Load("ressources/images/settings/moins1.png");
    A->img[1]=IMG_Load("ressources/images/settings/moins0.png");
    A->pos_img.w=61;
    A->pos_img.h=61;
    A->pos_img.x=-250+(SCREEN_W-A->pos_img.w)/2;
    A->pos_img.y=40+(SCREEN_H-A->pos_img.h)/2;
    A->state=0;
}

void initialiser_plus(image_double *A)
{
    A->img[0]=IMG_Load("ressources/images/settings/plus1.png");
    A->img[1]=IMG_Load("ressources/images/settings/plus0.png");
    A->pos_img.w=61;
    A->pos_img.h=61;
    A->pos_img.x=250+(SCREEN_W-A->pos_img.w)/2;
    A->pos_img.y=40+(SCREEN_H-A->pos_img.h)/2;
    A->state=0;
}

void initialiser_volume(image_volume *A)
{
    A->v[0]=IMG_Load("ressources/images/settings//volume/0.png");
    A->v[1]=IMG_Load("ressources/images/settings//volume/1.png");
    A->v[2]=IMG_Load("ressources/images/settings//volume/2.png");
    A->v[3]=IMG_Load("ressources/images/settings//volume/3.png");
    A->v[4]=IMG_Load("ressources/images/settings//volume/4.png");
    A->v[5]=IMG_Load("ressources/images/settings//volume/5.png");
    A->v[6]=IMG_Load("ressources/images/settings//volume/6.png");
    A->pos_img.w=362;
    A->pos_img.h=47;
    A->pos_img.x=(SCREEN_W-A->pos_img.w)/2;
    A->pos_img.y=40+(SCREEN_H-A->pos_img.h)/2;
}

void initialiser_return(image_double *A)
{
    A->img[0]=IMG_Load("ressources/images/settings/back1.png");
    A->img[1]=IMG_Load("ressources/images/settings/back0.png");
    A->pos_img.x=50;
    A->pos_img.y=50;
    A->pos_img.w=194;
    A->pos_img.h=72;
    A->state=0;
}

void initialiser_mute_unmute(Button BTM[])
{
    BTM[0].state=0;
    BTM[0].normal.img = IMG_Load("ressources/images/settings/mute1.png");
    BTM[0].normal.pos_img.w=81;
    BTM[0].normal.pos_img.h=81;
    BTM[0].normal.pos_img.x=((SCREEN_W-BTM[0].normal.pos_img.w)/2);
    BTM[0].normal.pos_img.y=(-60+(SCREEN_H-BTM[0].normal.pos_img.h)/2);

    BTM[0].hover.img = IMG_Load("ressources/images/settings/mute0.png");
    BTM[0].hover.pos_img.w=81;
    BTM[0].hover.pos_img.h=81;
    BTM[0].hover.pos_img.x=((SCREEN_W-BTM[0].hover.pos_img.w)/2);
    BTM[0].hover.pos_img.y=(-60+(SCREEN_H-BTM[0].hover.pos_img.h)/2);

    BTM[1].state=0;
    BTM[1].normal.img = IMG_Load("ressources/images/settings/unmute1.png");
    BTM[1].normal.pos_img.w=81;
    BTM[1].normal.pos_img.h=81;
    BTM[1].normal.pos_img.x=((SCREEN_W-BTM[1].normal.pos_img.w)/2);
    BTM[1].normal.pos_img.y=(-60+(SCREEN_H-BTM[1].normal.pos_img.h)/2);

    BTM[1].hover.img = IMG_Load("ressources/images/settings/unmute0.png");
    BTM[1].hover.pos_img.w=81;
    BTM[1].hover.pos_img.h=81;
    BTM[1].hover.pos_img.x=((SCREEN_W-BTM[1].hover.pos_img.w)/2);
    BTM[1].hover.pos_img.y=(-60+(SCREEN_H-BTM[1].hover.pos_img.h)/2);
}

void initialiser_normal_full(Button BTF[])
{
    BTF[0].state=0;
    BTF[0].normal.img = IMG_Load("ressources/images/settings/normal1.png");
    BTF[0].normal.pos_img.w=237;
    BTF[0].normal.pos_img.h=77;
    BTF[0].normal.pos_img.x=((SCREEN_W-BTF[0].normal.pos_img.w)/2);
    BTF[0].normal.pos_img.y=(140+(SCREEN_H-BTF[0].normal.pos_img.h)/2);

    BTF[0].hover.img = IMG_Load("ressources/images/settings/normal0.png");
    BTF[0].hover.pos_img.w=237;
    BTF[0].hover.pos_img.h=77;
    BTF[0].hover.pos_img.x=((SCREEN_W-BTF[0].hover.pos_img.w)/2);
    BTF[0].hover.pos_img.y=(140+(SCREEN_H-BTF[0].hover.pos_img.h)/2);

    BTF[1].state=0;
    BTF[1].normal.img = IMG_Load("ressources/images/settings/full1.png");
    BTF[1].normal.pos_img.w=237;
    BTF[1].normal.pos_img.h=77;
    BTF[1].normal.pos_img.x=((SCREEN_W-BTF[1].normal.pos_img.w)/2);
    BTF[1].normal.pos_img.y=(140+(SCREEN_H-BTF[1].normal.pos_img.h)/2);

    BTF[1].hover.img = IMG_Load("ressources/images/settings/full0.png");
    BTF[1].hover.pos_img.w=237;
    BTF[1].hover.pos_img.h=77;
    BTF[1].hover.pos_img.x=((SCREEN_W-BTF[1].hover.pos_img.w)/2);
    BTF[1].hover.pos_img.y=(140+(SCREEN_H-BTF[1].hover.pos_img.h)/2);
}




void option(SDL_Surface *screen)
{
    SDL_Event event;
    Mix_Chunk *mus;
    Button BTM[2];
    Button BTF[2];
    image IMAGE_OP,image_settings;
    image_double RETURN,MOINS,PLUS;
    image_volume VOLUME;
    int X_RTN,Y_RTN,X_MNS,Y_MNS,X_FULL,Y_FULL,X_MUT,Y_MUT,X_PLS;
    int volume,x,y,cond;
    int fullscreen = 1;
    int boucle=1;

    initialiser_BACK_settings(&IMAGE_OP);
    initialiser_image_settings(&image_settings);

    initialiser_return(&RETURN);
    initialiser_moins(&MOINS);
    initialiser_plus(&PLUS);
    initialiser_mute_unmute(BTM);
    initialiser_normal_full(BTF);
    initialiser_volume(&VOLUME);

    while(boucle)
    {
        afficher_imageBACK(screen,IMAGE_OP);
        afficher_imageBTN(screen,image_settings);
        afficher_image_double(&RETURN,screen);
        afficher_image_double(&MOINS,screen);
        afficher_image_double(&PLUS,screen);

        switch(fullscreen)
        {
        case 0:
            switch (BTF[1].state)
            {
            case 0:
                afficher_imageBTN(screen, BTF[1].normal);
                break;
            case 1:
                afficher_imageBTN(screen, BTF[1].hover);
                break;
            }
            break;
        case 1:
            switch (BTF[0].state)
            {
            case 0:
                afficher_imageBTN(screen, BTF[0].normal);
                break;
            case 1:
                afficher_imageBTN(screen, BTF[0].hover);
                break;
            }
            break;
        }

        X_RTN=calcul_X_IMGD(&RETURN);
        Y_RTN=calcul_Y_IMGD(&RETURN);
        X_MNS=calcul_X_IMGD(&MOINS);
        Y_MNS=calcul_Y_IMGD(&MOINS);
        X_FULL=calcul_XBTN(&BTF[0].normal);
        Y_FULL=calcul_YBTN(&BTF[0].normal);
        X_MUT=calcul_XBTN(&BTM[0].normal);
        Y_MUT=calcul_YBTN(&BTM[0].normal);
        X_PLS=calcul_X_IMGD(&PLUS);

        volume=Mix_VolumeMusic(-1);

        if(volume!=0)
        {
            switch (BTM[0].state)
            {
            case 0:
                afficher_imageBTN(screen, BTM[0].normal);
                break;
            case 1:
                afficher_imageBTN(screen, BTM[0].hover);
                break;
            }
        }
        else
        {
            switch (BTM[1].state)
            {
            case 0:
                afficher_imageBTN(screen, BTM[1].normal);
                break;
            case 1:
                afficher_imageBTN(screen, BTM[1].hover);
                break;
            }
        }

        switch(volume)
        {
        case 128:
            afficher_image_volume(&VOLUME,screen,6);
            break;
        default:
            afficher_image_volume(&VOLUME,screen,volume/20);;
            break;
        }

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:
                if(event.key.keysym.sym ==SDLK_ESCAPE)
                {
                    initialiser_audiobref(mus);
                    boucle=0;
                }

                if(event.key.keysym.sym ==SDLK_p)
                {
                    initialiser_audiobref(mus);
                    volume=increaseVolume();
                }

                if(event.key.keysym.sym ==SDLK_m)
                {
                    initialiser_audiobref(mus);
                    volume=decreaseVolume();
                }
                break;

            case SDL_MOUSEMOTION:
                x=event.motion.x;
                y=event.motion.y;

                if((y<=(Y_RTN+72) && y>=Y_RTN && x<=(X_RTN+194) && x>=X_RTN))
                {
                    initialiser_audiobref(mus);
                    RETURN.state=1;
                }
                else
                {
                    RETURN.state=0;
                }

                if((y<=(Y_MNS+61) && y>=Y_MNS && x<=(X_MNS+61) && x>=X_MNS))
                {
                    initialiser_audiobref(mus);
                    MOINS.state=1;
                }
                else
                {
                    MOINS.state=0;
                }

                if((y<=(Y_MNS+61) && y>=Y_MNS && x<=(X_PLS+61) && x>=X_PLS))
                {
                    initialiser_audiobref(mus);
                    PLUS.state=1;
                }
                else
                {
                    PLUS.state=0;
                }

                if((y<=(Y_FULL+77) && y>=Y_FULL && x<=(X_FULL+237) && x>=X_FULL))
                {
                    initialiser_audiobref(mus);
                    BTF[0].state=1;
                    BTF[1].state=1;
                }
                else
                {
                    BTF[0].state=0;
                    BTF[1].state=0;
                }

                if((y<=(Y_MUT+81) && y>=Y_MUT && x<=(X_MUT+81) && x>=X_MUT))
                {
                    initialiser_audiobref(mus);
                    BTM[0].state=1;
                    BTM[1].state=1;
                }
                else
                {
                    BTM[0].state=0;
                    BTM[1].state=0;
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                cond=event.button.button==SDL_BUTTON_LEFT;

                if(cond && (y<=(Y_RTN+72) && y>=Y_RTN && x<=(X_RTN+194) && x>=X_RTN) )
                {
                    RETURN.state=1;
                    boucle=0;
                }

                if(cond &&(y<=(Y_MNS+61) && y>=Y_MNS && x<=(X_MNS+61) && x>=X_MNS))
                {
                    MOINS.state=1;
                    volume=decreaseVolume();
                }

                if(cond &&(y<=(Y_MNS+61) && y>=Y_MNS && x<=(X_PLS+61) && x>=X_PLS))
                {
                    PLUS.state=1;
                    volume=increaseVolume();
                }

                if(cond &&(y<=(Y_FULL+77) && y>=Y_FULL && x<=(X_FULL+237) && x>=X_FULL))
                {
                    fullscreen = !fullscreen;
                    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, fullscreen ? SDL_FULLSCREEN :0|SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                    BTF[0].state=1;
                    BTF[1].state=1;
                }

                if(cond &&(y<=(Y_MUT+81) && y>=Y_MUT && x<=(X_MUT+81) && x>=X_MUT))
                {
                    if(volume!=0)
                    {
                        Mix_VolumeMusic(0);
                    }
                    else
                    {
                        Mix_VolumeMusic(128);
                    }
                    BTM[0].state=1;
                    BTM[1].state=1;
                }

                break;

            case SDL_QUIT:
                boucle=0;
                break;
            }
            SDL_Flip(screen);
        }
    }

    liberer_image(IMAGE_OP);
    liberer_image(image_settings);
    liberer_image_double(RETURN);
    liberer_image_double(MOINS);
    liberer_image_double(PLUS);
    liberer_image_volume(VOLUME);
    libererButtons(BTM,2);
    libererButtons(BTF,2);

}

