#pragma once
#include "allegro5/allegro.h"
// Esta clase se encarga del manejo del jugador
class NPC {
private:
    ALLEGRO_BITMAP* npc;
    float x, y;
    int ataca;
    int vida;
    int vidaAct;
    int def;
public:
    void inicia();
    void pinta2(float, float);
    float getx() { return x; };
    float gety() { return y; };
    void setx(float _x) { x = _x; };
    void sety(float _y) { y = _y; };
    ALLEGRO_BITMAP* getBitmap() { return npc; };
    void posiciona(float _x, float _y);
    bool atacando() { return ataca > 1; };
    void no_ataca() { ataca = -3; };
};