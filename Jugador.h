#ifndef JUGADOR_H
#define JUGADOR_H

#include "Personaje.h"

class Jugador : public Personaje
{
    public:
        SDL_Texture *textura, *textura_bala;
        SDL_Rect rect_textura, rect_bala;
        SDL_Renderer *renderer;

        void dibujar();
        void logica();

        Jugador(SDL_Renderer *renderer);
        virtual ~Jugador();
    protected:
    private:
};

#endif // JUGADOR_H
