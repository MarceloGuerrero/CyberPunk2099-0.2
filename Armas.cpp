#include "Armas.h"

#include <iostream>

using namespace std;

void Armas::pinta(int sx, int sy, int x, int y) {
    
    al_convert_mask_to_alpha(armas, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(armas, sx, sy * 45, 25, 45, x+7, y, NULL);
}

void Armas::inicia(int _x, int _y)
{
    armas = al_load_bitmap("IMG/16105.bmp");
    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    x = _x;
    y = _y;
}

Armas::~Armas() {

}

void Armas::draw(int sx, int sy, int x, int y) {


    if (direccion < 4) {
        sy = direccion;
        dir = sy;
        sx += (al_get_bitmap_width(armas) / 6) * sy;
    }
    else {
        //cout << "dir "<<  dir <<endl;
        sy = dir;
    }
    //cout << "sx " << sx << endl;


    pinta(sx, sy, x, y );
}