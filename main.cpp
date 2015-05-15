
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*nave,*enemigo,*bala;
SDL_Rect rect_background,rect_nave,rect_enemigo,rect_bala;

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 640/*WIDTH*/, 480/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
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
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    nave = IMG_LoadTexture(renderer, "nave.png");
    SDL_QueryTexture(nave, NULL, NULL, &w, &h);
    rect_nave.x = 0;
    rect_nave.y = 100;
    rect_nave.w = w;
    rect_nave.h = h;

    enemigo = IMG_LoadTexture(renderer, "enemigo.png");
    SDL_QueryTexture(enemigo,NULL,NULL,&w,&h);
    rect_enemigo.x = 400;
    rect_enemigo.y = 200;
    rect_enemigo.w = w;
    rect_enemigo.h = h;

    bala = IMG_LoadTexture(renderer, "bala.png");
    SDL_QueryTexture(bala,NULL,NULL,&w,&h);
    rect_bala.x = 100;
    rect_bala.y = 200;
    rect_bala.w = w;
    rect_bala.h = h;

    float enemigo_y = 0;

    //Main Loop
    float personaje_x = 100;
    float personaje_y = 100;
    list<SDL_Rect*>balas;
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
        }

        const Uint8* estaPresionada = SDL_GetKeyboardState( NULL );
        float velocidad = 1;
        if(estaPresionada[ SDL_SCANCODE_LSHIFT ])
        {
            velocidad = 0.5;
        }

        if( estaPresionada[ SDL_SCANCODE_UP ] )
        {
            personaje_y-=velocidad;
        }
        if( estaPresionada[ SDL_SCANCODE_DOWN ] )
        {
            personaje_y+=velocidad;
        }
        if( estaPresionada[ SDL_SCANCODE_LEFT ] )
        {
            personaje_x-=velocidad;
        }
        if( estaPresionada[ SDL_SCANCODE_RIGHT ] )
        {
            personaje_x+=velocidad;
        }
        if( estaPresionada[ SDL_SCANCODE_Z ] )
        {
            SDL_Rect *temp = new SDL_Rect;
            temp->w = rect_bala.w;
            temp->h = rect_bala.h;
            temp->x =personaje_x;
            temp->y =personaje_y;
            balas.push_back(temp);
        }
        rect_nave.x=personaje_x;
        rect_nave.y=personaje_y;

        enemigo_y+=1;
        if(enemigo_y>100)
            enemigo_y=0;

        rect_enemigo.y = enemigo_y;

        rect_bala.y++;

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, enemigo, NULL, &rect_enemigo);
        SDL_RenderCopy(renderer, nave, NULL, &rect_nave);

        for(list<SDL_Rect*>::iterator i=balas.begin();
            i!=balas.end();
            i++)
        {
            SDL_RenderCopy(renderer, bala, NULL, *i);
            (*i)->x+=5;
        }

        for(list<SDL_Rect*>::iterator i=balas.begin();
            i!=balas.end();
            i++)
        {
            SDL_RenderCopy(renderer, bala, NULL, *i);
            if((*i)->x>=500)
            {
                balas.erase(i);
                break;
            }
        }
//
//        if(balas.size()>1)
//        {
//            list<SDL_Rect*>::iterator ultimo=balas.end();
//            ultimo--;
//            if((*ultimo)->x>50)
//            {
//                balas.pop_back();
//            }
//        }

        SDL_RenderPresent(renderer);
    }

	return 0;
}
