#include "Jugador.h"

Jugador::Jugador(SDL_Renderer *renderer,list<Personaje*>*personajes)
{
    this->renderer = renderer;
    this->personajes = personajes;
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

    velocidad=3;
    velocidad_bala=10;
}

void Jugador::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
    for(int i=0;i<rect_balas.size();i++)
        SDL_RenderCopy(renderer, textura_bala, NULL, &rect_balas[i]);
}

void Jugador::logica()
{
    for(int i=0;i<rect_balas.size();i++)
        rect_balas[i].x+=velocidad_bala;

    const Uint8* estaPresionada = SDL_GetKeyboardState( NULL );
    if(estaPresionada[ SDL_SCANCODE_LEFT])
    {
        rect_textura.x-=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_RIGHT])
    {
        rect_textura.x+=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_UP])
    {
        rect_textura.y-=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_DOWN])
    {
        rect_textura.y+=velocidad;
    }
    if(estaPresionada[ SDL_SCANCODE_Z])
    {
        if(frame%10==0)
        {
            SDL_Rect temp;
            temp.x=rect_textura.x;
            temp.y=rect_textura.y;
            temp.w=rect_bala.w;
            temp.h=rect_bala.h;
            rect_balas.push_back(temp);
        }
    }
    for(list<Personaje*>::iterator i=personajes->begin();
        i!=personajes->end();
        i++
        )
    {
        if(*i==this)
            continue;
        for(int j=0;j<rect_balas.size();j++)
        {
            SDL_Rect rect1 = rect_balas[j];
            SDL_Rect rect2 = (*i)->rect_textura;
            if((rect1.x+rect1.w<rect2.x)==false//Muy a la izq
                && (rect1.x>rect2.x+rect2.w)==false//Muy a la der
                && (rect1.y+rect1.h<rect2.y)==false//Muy arriba
                && (rect1.y>rect2.y+rect2.h)==false//Muy abajo
               )
            {
                personajes->erase(i);
                return;
            }
        }
    }
    frame++;
}

Jugador::~Jugador()
{
    //dtor
}
