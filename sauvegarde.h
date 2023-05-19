#ifndef _SAUVEGARDE_H_
#define _SAUVEGARDE_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


/*
void sauvegarde_jeu(Background *bg, Character *perso, Ennemi *ennemi, AllObjet *all_objets, AllObjet *all_objets2, Minimap *minimap, Obstacle *obstacle, Score *score, tim *timer);

void load_jeu(Background *bg, Character *perso, Ennemi *ennemi, AllObjet *all_objets, AllObjet *all_objets2, Minimap *minimap, Obstacle *obstacle, Score *score, tim *timer);
*/



void sauvegarde_jeu(Background bg, Ennemi ennemi, Character character,AllObjet obj1,AllObjet obj2, tim* mytime);


void load_jeu(Background *bg, Ennemi *ennemi, Character *character,AllObjet *obj1,AllObjet *obj2, tim* mytime);



#endif
