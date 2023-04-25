#ifndef best_score_H
#define best_score_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void sauvgarder(char nomfich[],char nomjoueur[],int score);
void meilleiur(char nomfich[] ,char Nomjoueur[],int *score);
int best_scr (char bestnom[],int bscr);
#endif
