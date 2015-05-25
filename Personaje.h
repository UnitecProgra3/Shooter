#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class Personaje
{
    public:
        SDL_Texture *textura, *textura_bala;
        SDL_Rect rect_textura, rect_bala;
        SDL_Renderer *renderer;

        int frame;
        Personaje();
        virtual void logica()=0;
        virtual void dibujar()=0;
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
