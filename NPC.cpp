#include "NPC.h"
#include <iostream>

using namespace std;

void NPC::posiciona(int _x, int _y) {
    x = _x;
    y = _y;
}

void NPC::inicia()
{
    npc = al_load_bitmap("IMG/4083.bmp");
    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    x = 500;
    y = 500;
}

void NPC::pinta2(int sx, int sy) {

    al_draw_bitmap_region(npc, sx, sy * al_get_bitmap_height(npc) / 4, al_get_bitmap_width(npc) / 8, al_get_bitmap_height(npc) / 4, x, y, NULL);

}