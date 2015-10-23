
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character, *playerGoku;
SDL_Rect rect_background,rect_character, rect_playerGoku;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 400; rect_character.y = 100; rect_character.w = w; rect_character.h = h;

    playerGoku = IMG_LoadTexture(renderer, "goku.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_playerGoku.x = 100; rect_playerGoku.y = 100; rect_playerGoku.w = w; rect_playerGoku.h = h;

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_a)
                    rect_playerGoku.x-=5;
                if(Event.key.keysym.sym == SDLK_s)
                    rect_playerGoku.x+=5;
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x-=5;
                if(Event.key.keysym.sym == SDLK_f)
                    rect_character.x+=5;
            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, playerGoku, NULL, &rect_playerGoku);
        SDL_RenderPresent(renderer);
    }

	return 0;
}
