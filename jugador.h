#pragma once
#include "allegro5/allegro.h"
#include "Armas.h"


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
    float moveSpeed;
public:
    void inicia();
    void pinta(int, int);
    void teclado(Armas arma1, ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events,
        bool done, int &sourceX, int &sourceY, int &dir, bool draw, bool active, int moveSpeed, ALLEGRO_TIMER* Timer, ALLEGRO_TIMER* frameTimer);
    int getx() { return x; };
    int gety() { return y; };
    int getAtk() { return ataca; };
    float getSpeed() { return moveSpeed; };
    void setAtk(int Atk) { ataca = Atk; };
    void setx(int _x) { x = _x; };
    void sety(int _y) { y = _y; };
    void setpx(int _x) { x += _x; };
    void setmx(int _y) { y -= _y; };
    void setpy(int _x) { x += _x; };
    void setmy(int _y) { y -= _y; };
    void setSpeed(float _moveSpeed) { moveSpeed = _moveSpeed; };
    void setpSpeed(float _moveSpeed) { moveSpeed += _moveSpeed; };
    void setmSpeed(float _moveSpeed) { moveSpeed -= _moveSpeed; };
    ALLEGRO_BITMAP* getBitmap() { return p1; };
    void posiciona(int _x, int _y);
    bool atacando() { return ataca > 1; };
    void no_ataca() { ataca = -3; };
};



