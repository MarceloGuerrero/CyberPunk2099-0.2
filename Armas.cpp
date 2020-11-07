#include "Armas.h"


//#include <iostream>

//using namespace std;

void Armas::pinta(int sx, int sy, int x, int y) {
    int xx;
    al_convert_mask_to_alpha(armas, al_map_rgb(0, 0, 0));

    xx = x;
    if (dirA == 2) xx -=5;
    if (dirA == 3) xx += 10;
    al_draw_bitmap_region(armas, sx, dirA * 45, 20, 45, xx, y, NULL);
}

void Armas::inicia(int _x, int _y)
{
    armas = al_load_bitmap("IMG/16105.bmp");
    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    x = _x;
    y = _y;
    dmg = 3;
}

Armas::~Armas() {
}

void Armas::draw(int sx, int sy, int x, int y) {
    
    /*if (direccion < 4) {
        sy = direccion;
        dirA = sy;
        sx += (al_get_bitmap_width(armas) / 6) * sy;
    }
    else {
        //cout << "dir "<<  dir <<endl;
        sy = dirA;
    }
    //cout << "sx " << sx << endl;


    pinta(sx, sy, x, y );*/
}

void Armas::cmd(jugador jugador, int sx, int sy)
{
    if (sy == 2) direccion = RIGHT1;
    if (sy == 1) direccion = LEFT1;
    if (sy == 3) direccion = UP1;
    if (sy == 0) direccion = DOWN1;
}

void Armas::update()
{
    switch (direccion) {
    case RIGHT1:
        dirA = 3;
        break;
    case LEFT1:
        dirA = 2;
        break;
    case UP1:
        dirA = 1;
        break;
    case DOWN1:
        dirA = 1;
        break;
    case QUIETO1:
      
        break;
    case ATACANDO1:
        
        break;
    }
}