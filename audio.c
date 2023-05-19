#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "audio.h"

void initialiser_audio (Mix_Music *music)
{
if (Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1){
printf("%s", SDL_GetError());
}
music=Mix_LoadMUS ("ressources/audio/music.mp3");
Mix_PlayMusic(music,-1);
}


void liberer_musique (Mix_Music *music)
{
Mix_FreeMusic (music);
}


void initialiser_audiobref (Mix_Chunk *music)
{
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
music = Mix_LoadWAV("ressources/audio/clic.wav");
Mix_PlayChannel( -1, music, 0);
if (music==NULL) printf("%s", SDL_GetError());
}

void liberer_musiquebref (Mix_Chunk *music)
{
Mix_FreeChunk (music);
}


int increaseVolume() {
    int volume = Mix_VolumeMusic(-1);
    if (volume + 20 > 128) {
        return Mix_VolumeMusic(128);
    } else {
        return Mix_VolumeMusic(volume + 20);
    }
}


int decreaseVolume() {
    int volume = Mix_VolumeMusic(-1);
    if (volume - 20 <= 0) {
        return Mix_VolumeMusic(0);
    } else {
        return Mix_VolumeMusic(volume - 20);
    }
}





