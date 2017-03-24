#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character, *my_image, *a1, *a2;
SDL_Rect rect_background,rect_character, my_rect, rect_a1, rect_a2;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Wall-E and Rafael", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
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
    background = IMG_LoadTexture(renderer,"2.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    character = IMG_LoadTexture(renderer,"4.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 20;
    rect_character.y = 0;
    rect_character.w = w;
    rect_character.h = h;

    my_image = IMG_LoadTexture(renderer,"5.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    my_rect.x = 400;
    my_rect.y = -150;
    my_rect.w = w;
    my_rect.h = h;

    a1=IMG_LoadTexture(renderer,"6.png");
    SDL_QueryTexture(a1, NULL, NULL, &w, &h);
    rect_a1.x = 200;
    rect_a1.y = 0;
    rect_a1.w = w;
    rect_a1.h = h;

    a2=IMG_LoadTexture(renderer,"7.png");
    SDL_QueryTexture(a1, NULL, NULL, &w, &h);
    rect_a2.x = 350;
    rect_a2.y = -125;
    rect_a2.w = w;
    rect_a2.h = h;



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
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_character.x--;
                if(Event.key.keysym.sym == SDLK_w)
                    rect_character.y--;
                if(Event.key.keysym.sym == SDLK_s)
                    rect_character.y++;
            }
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if( currentKeyStates[ SDL_SCANCODE_UP ] )
        {
            rect_character.y--;
        }
        if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
        {
            rect_character.y++;
        }
        if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
        {
            rect_character.x--;
        }
        if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
        {
            rect_character.x++;
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, my_image, NULL, &my_rect);
        SDL_RenderCopy(renderer, a1, NULL, &rect_a1);
        SDL_RenderCopy(renderer, a2, NULL, &rect_a2);
        SDL_RenderPresent(renderer);

        SDL_Delay(15);
    }

	return 0;
}
