using namespace std;
#include<SDL.h> 
#include<SDL_ttf.h> 
#include<iostream>
#include "config_sdl.h"
#include <fstream>
#include <sstream>
#include "SDL_image.h"
#include<ctime>


SDL_Renderer* rendu; TTF_Font* font; SDL_TimerID timer;


//--------------------------------------------------Fonctions SDL----------------------------------------------------------- //

// Fond
void fond(SDL_Renderer* rendu) {
    char name[] = "fond_pixel.bmp";
    char name2[] = "herbev2.bmp";

    SDL_Surface* image = SDL_LoadBMP(name);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(rendu, image);

    SDL_Rect dstrect = { 0,0,1100,700 };
    SDL_RenderCopy(rendu, texture, NULL, &dstrect);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture);

    SDL_Surface* image2 = SDL_LoadBMP(name2);
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(rendu, image2);

    SDL_Rect dstrect2 = { 0,600,1080,100 };
    SDL_RenderCopy(rendu, texture2, NULL, &dstrect2);
    SDL_RenderPresent(rendu);
    SDL_DestroyTexture(texture2);
}


//Uint32 event1(Uint32 interval, void* param)
// retunr interval

// ----------------------------------------------Fin fonctions SDL----------------------------------------------------------- //

int main(int argn, char* argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) { cout << "Echec à l’ouverture"; return 1; } TTF_Init(); font = TTF_OpenFont("C:\\Windows\\Fonts\\calibri.ttf", 15); SDL_Window* win = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1360, 720, SDL_WINDOW_SHOWN); if (win == NULL) cout << "erreur ouverture fenetre"; rendu = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    fond(rendu);

    /*************BOUCLE D'evenements**************/

    bool continuer = true;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:

            continuer = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_a) { //touche a
            }

            if (event.key.keysym.sym == SDLK_b) { //touche b
                //timer = SDL_AddTimer(interval, event2, NULL);
                //SDL_RemoveTimer(timer);
            }
            break;
        }

    }

    
    
    SDL_DestroyRenderer(rendu); SDL_DestroyWindow(win); TTF_CloseFont(font); TTF_Quit(); SDL_Quit();

    return 0;
}
