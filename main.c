#include "enigmealeatoiravecfichier.h"
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_BPP = 32;

SDL_Surface *background = NULL, *yes=NULL;
SDL_Surface *screen = NULL;
enigme e;

int main( int argc, char* args[] )
{
    SDL_Event event;
    char repjoueur[30];
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
    int continuer = 1;
    int x,y,result=0;
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    genererEnigme(&e,"enigmequestion.txt","enigmechoix.txt","enigmereponse.txt");
    background = LoadImage( "Background.bmp" );
    yes = LoadImagepng( "yes.png" );
    SDL_WM_SetCaption( "Hello World", NULL );
    printf("%s %s %s %s",e.c[0],e.c[1],e.c[2],e.rep);
    while(continuer==1)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                SDL_Quit();
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                case SDL_BUTTON_LEFT:
                SDL_GetMouseState(&x,&y);
                if(x>143 && y>359 && x<425 && y<445)
                {
                    SDL_PumpEvents();


                        apply_surface(530,530,yes,screen);

                        SDL_Flip(screen);
                        SDL_Delay(1000);

                }
                else if(x>143 && y>359 && x<425 && y<445)
                {
                    SDL_PumpEvents();

                    if(strcmp(e.c[1],e.rep)==0)
                    {
                        apply_surface(530,530,yes,screen);

                        SDL_Flip(screen);
                        SDL_Delay(1000);
                    }
                }
                else if(x>143 && y>359 && x<425 && y<445)
                {
                    SDL_PumpEvents();

                    if (strcmp(e.c[1],e.rep)==0)
                    {
                        apply_surface(530,530,yes,screen);

                        SDL_Flip(screen);
                        SDL_Delay(1000);
                    }
                }
                break;
                }

            }
        }

        apply_surface( 0, 0, background, screen );
        afficherEnigme(e, screen);
        SDL_Flip(screen);
    }
        SDL_FreeSurface( background );
        TTF_Quit();
        SDL_Quit();
    return EXIT_SUCCESS;
}
