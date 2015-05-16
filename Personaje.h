#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class Personaje
{
    public:
        Personaje();
        virtual void logica()=0;
        virtual void dibujar()=0;
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
