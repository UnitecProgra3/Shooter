#include "Jugador.h"

Jugador::Jugador(SDL_Renderer *renderer)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "nave.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 0;
    rect_textura.y = 100;
    rect_textura.w = w;
    rect_textura.h = h;

    textura_bala = IMG_LoadTexture(renderer, "bala.png");
    SDL_QueryTexture(textura_bala, NULL, NULL, &w, &h);
    rect_bala.x = 0;
    rect_bala.y = 100;
    rect_bala.w = w;
    rect_bala.h = h;
}

void Jugador::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void Jugador::logica()
{
    const Uint8* estaPresionada = SDL_GetKeyboardState( NULL );
    if(estaPresionada[ SDL_SCANCODE_A])
    {
        rect_textura.x--;
    }
    if(estaPresionada[ SDL_SCANCODE_D])
    {
        rect_textura.x++;
    }
    if(estaPresionada[ SDL_SCANCODE_W])
    {
        rect_textura.y--;
    }
    if(estaPresionada[ SDL_SCANCODE_S])
    {
        rect_textura.y++;
    }
}

Jugador::~Jugador()
{
    //dtor
}
