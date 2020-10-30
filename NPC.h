#pragma once
#include "allegro5/allegro.h"
// Esta clase se encarga del manejo del jugador
class NPC {
private:
    ALLEGRO_BITMAP* npc;
    int x, y;
    int ataca;
    int vida;
    int vidaAct;
    int def;
public:
    void inicia();
    void pinta2(int, int);
    int getx() { return x; };
    int gety() { return y; };
    void setx(int _x) { x = _x; };
    void sety(int _y) { y = _y; };
    ALLEGRO_BITMAP* getBitmap() { return npc; };
    void posiciona(int _x, int _y);
    bool atacando() { return ataca > 1; };
    void no_ataca() { ataca = -3; };
};