#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"

class Enemigo : public Personaje
{
    public:
        SDL_Texture *textura, *textura_bala;
        SDL_Rect rect_textura, rect_bala;
        SDL_Renderer *renderer;

        void dibujar();
        void logica();

        Enemigo(SDL_Renderer* renderer);
        virtual ~Enemigo();
    protected:
    private:
};

#endif // ENEMIGO_H
