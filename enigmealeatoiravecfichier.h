#ifndef ENIGMEALEATOIRAVECFICHIER_INCLUDED
#define ENIGMEALEATOIRAVECFICHIER_INCLUDED
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <signal.h>
#include <unistd.h>
#include <SDL/SDL_mixer.h>
typedef struct
{
    char question[100];
    char c[3][100];
    char rep[100];
} enigme;
SDL_Surface *LoadImage(const char *fichier_image);
SDL_Surface *LoadImagepng(const char *fichier_image);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
void genererEnigme(enigme * e,char * fquestion,char * fchoix,char * freponse);
void afficherEnigme(enigme e, SDL_Surface * screen);

#endif
