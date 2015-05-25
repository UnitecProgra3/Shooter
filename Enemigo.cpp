#include "Enemigo.h"

Enemigo::Enemigo(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    int w,h;
    textura = IMG_LoadTexture(renderer, "enemigo.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 200;
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

void Enemigo::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
}

void Enemigo::logica()
{
    rect_textura.y+=1;
}

Enemigo::~Enemigo()
{
    //dtor
}
