#include "Armas.h"

#include <iostream>

using namespace std;

void Armas::pinta(int sx, int sy, int x, int y) {
    al_convert_mask_to_alpha(armas, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(armas, sx, sy * 45, 25, 45, x, y, NULL);
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