#pragma once
#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
//#include "allegro5/allegro.h"



// Esta clase se encarga del manejo del jugador
class player
{
private:
    ALLEGRO_BITMAP* p1;
    int x, y;
    /*int direccion;
    int animacion;*/
    int ataca;
public:
    int direccion;
    int animacion;
    void inicia();
    void pinta();
    //void teclado();
    int getx() { return x; };
    int gety() { return y; };
    void posiciona(int _x, int _y);
    bool atacando() { return ataca > 1; };
    void no_ataca() { ataca = -3; };
};


void player::inicia()
{
    p1 = al_load_bitmap("IMG/allen2.bmp");
    // inicializar vbles
    direccion = 0;
    animacion = 0;
    x = 620;
    y = 362;
}
void player::pinta(){
/*
    //TODO: me falta hacer todo para que ataque

    if ( ataca > 1 && ( direccion == 1 || direccion == 3 ) )
    {
           masked_blit(p1, buffer, 0, direccion*96, x-32, y-32, 96,96);
    }

    masked_blit(p1, buffer, animacion*32, direccion*32, x, y, 32,32);

    if ( ataca > 1 && ( direccion == 0 || direccion == 2 ) )
    {
           masked_blit(p1, buffer, 0, direccion*96, x-32, y-32, 96,96);
    }
    if ( ataca > 1 || ataca < 0) ataca++;
    
    al_draw_bitmap_region(p1,animacion * 32, direccion * 48, x, y, 32, 48,ALLEGRO_FLIP_HORIZONTAL );*/
}

/*void player::teclado(){
    int ax = x;
    int ay = y;
    // teclas control usuario
    if (al_key_down(ALLEGRO_EVENT_KEY_DOWN, ALLEGRO_KEY_DOWN){
        y -= desplazamiento;
        direccion = 3;
    }
    if (key[KEY_S]){
        y += desplazamiento;
        direccion = 0;
    }
    if (key[KEY_A]){
        x -= desplazamiento;
        direccion = 1;
    }
    if (key[KEY_D]){
        x += desplazamiento;
        direccion = 2;
    }

    /*if (key[KEY_SPACE] && ataca == 0)
    {
        ataca = 1;
    }
    if (!key[KEY_SPACE] && ataca == 1)
    {
        ataca = 2;

    }

    if (ax != x || ay != y){
        // entra si a cambiado alguna de las variables x,y
        animacion++;
        if (animacion > 2) animacion = 0;
    }

    // limites
    if (x < 0) x = 0;
    if (x > PANTALLA_ANCHO) x = PANTALLA_ANCHO;
    if (y < 0) y = 0;
    if (y > PANTALLA_ALTO)  y = PANTALLA_ALTO;
}*/

void player::posiciona(int _x, int _y){
    x = _x;
    y = _y;
}

#endif // USER_H_INCLUDED