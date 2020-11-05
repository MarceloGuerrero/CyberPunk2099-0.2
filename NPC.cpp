#include "NPC.h"
#include <iostream>
using namespace std;
void NPC::posiciona(float _x, float _y) {
    x = _x;
    y = _y;
}

void NPC::sufre_daño(int dmg, NPC &guardia)
{
    //muerto = false;

    if (!muerto)
    {
        vidaAct-= dmg;
        cout << "vidita" << vidaAct << endl;
        if (vidaAct <= 0)
        {
            muerto = true;
            guardia.~NPC();
        }
    }
}

NPC::~NPC()
{
    if (muerto) {
       // al_destroy_bitmap(npc);
    }
}



NPC::NPC(int _vida)
{
    vida = _vida;
    vidaAct = vida;
    cout << "esta es la vida: " << vida << endl;
    cout << "esta es la vida actual: " << vidaAct << endl;
}

void NPC::inicia()
{
    npc = al_load_bitmap("IMG/4083.bmp");
    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    this->x = 500;
    this->y = 500;
}


void NPC::pinta2(float sx, float sy) {
    al_convert_mask_to_alpha(npc, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(npc, sx, sy * 46, 30, 46, x, y, NULL);
}