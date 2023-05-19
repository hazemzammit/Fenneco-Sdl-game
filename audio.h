#ifndef FONCTION_H 
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

void initialiser_audio (Mix_Music *music);
void liberer_musique (Mix_Music *music);

void initialiser_audiobref(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music) ;

int increaseVolume();
int decreaseVolume();

#endif


