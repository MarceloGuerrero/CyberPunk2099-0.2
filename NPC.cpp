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
    al_convert_mask_to_alpha(npc, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(npc, sx, sy * 46, 30, 46, x, y, NULL);
}