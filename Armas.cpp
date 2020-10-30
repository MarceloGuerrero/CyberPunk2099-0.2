#include "Armas.h"

#include <iostream>

using namespace std;

void Armas::pinta(int sx, int sy) {

    al_draw_bitmap_region(arma1, sx, sy * al_get_bitmap_height(arma1) / 4, al_get_bitmap_width(arma1) / 6, al_get_bitmap_height(arma1) / 4, x, y, NULL);


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

void Armas::inicia(int _x, int _y)
{
    arma1 = al_load_bitmap("IMG/16105.bmp");
    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    x = _x;
    y = _y;
}