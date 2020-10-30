#pragma once
#include "allegro5/allegro.h"



// Esta clase se encarga del manejo del jugador
class jugador {
private:
    ALLEGRO_BITMAP* p1;
    int x, y;
    /*int direccion;
    int animacion;*/
    int ataca;
    int vida;
    int mana;
    int aguante;
    int defBase;
public:
    void inicia();
    void pinta(int, int);
    //void teclado(player jugador);
    int getx() { return x; };
    int gety() { return y; };
    void setx(int _x) { x = _x; };
    void sety(int _y) { y = _y; };
    ALLEGRO_BITMAP* getBitmap() { return p1; };
    void posiciona(int _x, int _y);
    bool atacando() { return ataca > 1; };
    void no_ataca() { ataca = -3; };
};



