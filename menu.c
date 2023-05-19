#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "audio.h"
#include "image.h"
#include "texte.h"
#include "option.h"
#include "menu.h"
#include "game.h"
#include "submenu.h"
#include "signin.h"
#include "congrats.h"

void initialiser_back_menu (image *imge)
{
    imge->img=IMG_Load("ressources/images/menu/menu_back.png");
    imge->pos_img.x=0;
    imge->pos_img.y=0;
    imge->pos_img.h=SCREEN_H;
    imge->pos_img.w=SCREEN_W;
}

void initialiser_image_menu(image *imgbtn)
{
    imgbtn->img=IMG_Load("ressources/images/menu/menu.png");
    imgbtn->pos_img.w=317;
    imgbtn->pos_img.h=424;
    imgbtn->pos_img.x=(SCREEN_W-imgbtn->pos_img.w)/10;
    imgbtn->pos_img.y=((SCREEN_H-imgbtn->pos_img.h)/2);
}

void initButtons(Button buttons[])
{

    buttons[0].state=0;
    buttons[0].normal.img = IMG_Load("ressources/images/menu/play0.png");
    buttons[0].normal.pos_img.w=227;
    buttons[0].normal.pos_img.h=62;
    buttons[0].normal.pos_img.x=((SCREEN_W-buttons[0].normal.pos_img.w+317)/10);
    buttons[0].normal.pos_img.y=(50+(SCREEN_H-buttons[0].normal.pos_img.h)/3);

    buttons[0].hover.img = IMG_Load("ressources/images/menu/play1.png");
    buttons[0].hover.pos_img.w=227;
    buttons[0].hover.pos_img.h=62;
    buttons[0].hover.pos_img.x=((SCREEN_W-buttons[0].hover.pos_img.w+317)/10);
    buttons[0].hover.pos_img.y=(50+(SCREEN_H-buttons[0].hover.pos_img.h)/3);


    buttons[1].state=0;
    buttons[1].normal.img = IMG_Load("ressources/images/menu/settings0.png");
    buttons[1].normal.pos_img.w=227;
    buttons[1].normal.pos_img.h=62;
    buttons[1].normal.pos_img.x=((SCREEN_W-buttons[1].normal.pos_img.w+317)/10);
    buttons[1].normal.pos_img.y=(140+(SCREEN_H-buttons[1].normal.pos_img.h)/3);

    buttons[1].hover.img = IMG_Load("ressources/images/menu/settings1.png");
    buttons[1].hover.pos_img.w=227;
    buttons[1].hover.pos_img.h=62;
    buttons[1].hover.pos_img.x=((SCREEN_W-buttons[1].hover.pos_img.w+317)/10);
    buttons[1].hover.pos_img.y=(140+(SCREEN_H-buttons[1].hover.pos_img.h)/3);


    buttons[2].state=0;
    buttons[2].normal.img = IMG_Load("ressources/images/menu/quit0.png");
    buttons[2].normal.pos_img.w=227;
    buttons[2].normal.pos_img.h=62;
    buttons[2].normal.pos_img.x=((SCREEN_W-buttons[2].normal.pos_img.w+317)/10);
    buttons[2].normal.pos_img.y=(230+(SCREEN_H-buttons[2].normal.pos_img.h)/3);

    buttons[2].hover.img = IMG_Load("ressources/images/menu/quit1.png");
    buttons[2].hover.pos_img.w=227;
    buttons[2].hover.pos_img.h=62;
    buttons[2].hover.pos_img.x=((SCREEN_W-buttons[2].hover.pos_img.w+317)/10);
    buttons[2].hover.pos_img.y=(230+(SCREEN_H-buttons[2].hover.pos_img.h)/3);

}

int check_button_hover(Button buttons[], int num_buttons, int x, int y)
{
    int X_BTN,Y_BTN;
    for (int i = 0; i < num_buttons; i++)
    {
        Button button = buttons[i];
        X_BTN=calcul_XBTN(&buttons[i].normal);
        Y_BTN=calcul_YBTN(&buttons[i].normal);
        if (x >= X_BTN && x < X_BTN + 227 && y >= Y_BTN && y < Y_BTN + 62)
        {
            return i;
        }
    }
    return -1;
}

void menu(SDL_Surface *screen)
{
    image IMAGE_BACK,image_menu;
    Mix_Chunk *mus;
    Mix_Music *music;
    SDL_Event event;
    int boucle=1;
    Button buttons[3];
    int currentButton = -1;
    int i,x,y,cond;
    initialiser_audio(music);
    initialiser_back_menu(&IMAGE_BACK);
    initialiser_image_menu(&image_menu);
    initButtons(buttons);

    while(boucle)
    {
        afficher_imageBACK(screen,IMAGE_BACK);
        afficher_imageBTN(screen,image_menu);

        switch (buttons[0].state)
        {
        case 0:
            afficher_imageBTN(screen, buttons[0].normal);
            break;
        case 1:
            afficher_imageBTN(screen, buttons[0].hover);
            break;
        }
        switch (buttons[1].state)
        {
        case 0:
            afficher_imageBTN(screen, buttons[1].normal);
            break;
        case 1:
            afficher_imageBTN(screen, buttons[1].hover);
            break;
        }
        switch (buttons[2].state)
        {
        case 0:
            afficher_imageBTN(screen, buttons[2].normal);
            break;
        case 1:
            afficher_imageBTN(screen, buttons[2].hover);
            break;
        }



        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_DOWN)
                {
                    initialiser_audiobref(mus);
                    currentButton++;
                    if (currentButton >= 3)
                    {
                        currentButton = 0;
                    }
                }
                else if (event.key.keysym.sym == SDLK_UP)
                {
                    initialiser_audiobref(mus);
                    currentButton--;
                    if (currentButton < 0)
                    {
                        currentButton = 2;
                    }
                }
                else if (event.key.keysym.sym == SDLK_RETURN)
                {
                    switch (currentButton)
                    {
                    case 0:
                    submenuL(screen);

                        break;
                    case 1:
                        option(screen);
                        break;
                    case 2:
                        boucle=0;
                        break;
                    }
                }
                for (int i = 0; i < 3; i++)
                {
                    if (i == currentButton)
                    {
                        buttons[i].state = 1;
                    }
                    else
                    {
                        buttons[i].state = 0;
                    }
                }

                if(event.key.keysym.sym ==SDLK_ESCAPE)
                {
                    initialiser_audiobref(mus);
                    boucle=0;
                }
                if(event.key.keysym.sym ==SDLK_o)
                {
                    option(screen);
                }

                  if(event.key.keysym.sym ==SDLK_j)
                {
  submenuL(screen);
                }
                break;


            case SDL_MOUSEMOTION:
                x=event.motion.x;
                y=event.motion.y;
                int hovered_button = check_button_hover(buttons, 3, x, y);
                for ( i = 0; i < 3; i++)
                {
                    if (i == hovered_button)
                    {
                        buttons[i].state = 1;
                        initialiser_audiobref(mus);
                    }
                    else
                    {
                        buttons[i].state = 0;
                    }
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                cond=event.button.button==SDL_BUTTON_LEFT;
                x=event.motion.x;
                y=event.motion.y;
                hovered_button = check_button_hover(buttons, 3, x, y);
                switch (hovered_button)
                {
                case 0:
                      submenuL(screen);
                    break;
                case 1:
                    option(screen);
                    break;
                case 2:
                    boucle=0;
                    break;
                }
                break;

            case SDL_QUIT:
                boucle=0;
                break;
            }

            SDL_Flip(screen);
        }

    }

    liberer_image(IMAGE_BACK);
    liberer_image(image_menu);
    libererButtons(buttons,3);
    liberer_musiquebref(mus);
    liberer_musique(music);



}



