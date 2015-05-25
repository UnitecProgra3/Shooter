#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"

class Enemigo : public Personaje
{
    public:
        void dibujar();
        void logica();

        Enemigo(SDL_Renderer* renderer);
        virtual ~Enemigo();
    protected:
    private:
};

#endif // ENEMIGO_H
