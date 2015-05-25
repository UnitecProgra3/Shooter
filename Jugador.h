#ifndef JUGADOR_H
#define JUGADOR_H

#include "Personaje.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Jugador : public Personaje
{
    public:
        vector<SDL_Rect> rect_balas;
        list<Personaje*>*personajes;
        int velocidad;
        int velocidad_bala;

        void dibujar();
        void logica();

        Jugador(SDL_Renderer *renderer,list<Personaje*>*personajes);
        virtual ~Jugador();
    protected:
    private:
};

#endif // JUGADOR_H
