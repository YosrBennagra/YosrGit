#include "enigmealeatoiravecfichier.h"
SDL_Surface *LoadImage(const char *fichier_image)
{
    SDL_Surface *image_optimized;
    SDL_Surface *image_tmp = SDL_LoadBMP(fichier_image);
    if (image_tmp == NULL)
    {
        printf("Image %s introuvable !\n", fichier_image);
        SDL_Quit;
        system ("pause");
        exit(-1);
    }

    image_optimized = SDL_DisplayFormat(image_tmp);
    SDL_FreeSurface(image_tmp);
    return image_optimized;
}
SDL_Surface *LoadImagepng(const char *fichier_image)
{
    SDL_Surface *image_optimized;
    SDL_Surface *image_tmp = IMG_Load(fichier_image);
    if (image_tmp == NULL)
    {
        printf("Image %s introuvable !\n", fichier_image);
        SDL_Quit;
        system ("pause");
        exit(-1);
    }

    image_optimized = SDL_DisplayFormatAlpha(image_tmp);
    SDL_FreeSurface(image_tmp);
    return image_optimized;
}
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}
void genererEnigme(enigme * e,char * fquestion,char * fchoix,char * freponse)
{
    int i,r;

    FILE *fq=NULL;
    FILE *fc=NULL;
    FILE *fr=NULL;
    fq=fopen(fquestion,"r");
    fc=fopen(fchoix,"r");
    fr=fopen(freponse,"r");
    srand(time(NULL));
    r = rand() % 4;
    for (i=0 ; i<=r ; i++)
    {
        fgets(e->question, sizeof(e->question),fq);
        fscanf(fc,"%s %s %s",e->c[0], e->c[1], e->c[2]);
        fgets(e->rep, sizeof(e->rep),fr);
    }

    return e;
}
void afficherEnigme(enigme e, SDL_Surface * screen)
{
    SDL_Surface * Questiontxt=NULL, * choix0=NULL, * choix1=NULL, *choix2=NULL, * choix3=NULL, *enigmeBG;
    TTF_Font *police=NULL;
    enigmeBG = LoadImagepng( "enigme.png" );
    SDL_Color CouleurNoir = {0,0,0};
    police = TTF_OpenFont("font.ttf",25);
    apply_surface(0,0,enigmeBG,screen);
    Questiontxt = TTF_RenderText_Blended(police,e.question,CouleurNoir);
    choix0      = TTF_RenderText_Blended(police,e.c[0],CouleurNoir);
    choix1      = TTF_RenderText_Blended(police,e.c[1],CouleurNoir);
    choix2      = TTF_RenderText_Blended(police,e.c[2],CouleurNoir);
    // choix3      = TTF_RenderText_Blended(police,e.c[3],CouleurBlanche);
    //Les Blits
    apply_surface( 76, 175, Questiontxt, screen );
    apply_surface( 163, 400, choix0, screen );
    apply_surface( 870, 400, choix1, screen );
    apply_surface( 163, 602, choix2, screen );
    SDL_Flip(screen);
}


