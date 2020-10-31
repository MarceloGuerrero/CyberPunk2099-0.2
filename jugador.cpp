#include "jugador.h"
#include <iostream>

using namespace std;
void jugador::inicia()
{
    p1 = al_load_bitmap("IMG/allen2.bmp");
    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    x = 620;
    y = 362;
}
void jugador::pinta(int sx, int sy) {
    al_convert_mask_to_alpha(p1, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(p1, sx, sy * 50, 32, 50, x, y, NULL);


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

void jugador::teclado(Armas arma1, ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events,
    bool done, int& sourceX, int& sourceY, int& dir, bool draw, bool active, int moveSpeed) {

    enum Direction { DOWN, LEFT, RIGHT, UP };

    al_wait_for_event(event_queue, &events);
    al_get_keyboard_state(&keyState);
    if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        done = true;
    }
    else if (events.type == ALLEGRO_EVENT_TIMER) {
        active = true;
        if (al_key_down(&keyState, ALLEGRO_KEY_S)) {
            this->y += moveSpeed;
            dir = DOWN;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_W)) {
            this->y -= moveSpeed;
            dir = UP;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
            moveSpeed = 5;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_D)) {
            this->x += moveSpeed;
            dir = RIGHT;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_A)) {
            this->x -= moveSpeed;
            dir = LEFT;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_LCTRL && ataca == 0)) {
            ataca = 1;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_LCTRL && ataca == 1)) {
            ataca = 2;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
        {
            done = true;
        }
        else {
            active = false;
        }

    }
    if (active) {
        sourceX += al_get_bitmap_width(this->getBitmap()) / 3;
        //sourceX += al_get_bitmap_width(arma1.getBitmap()) / 6;
    }
    else {
        sourceX = 32;
    }
    if (sourceX >= al_get_bitmap_width(this->getBitmap())) {
        sourceX = 0;
    }
    sourceY = dir;
    draw = true;
    if (draw) {
        this->setx(x);
        this->sety(y);
        arma1.setx(this->getx());
        arma1.sety(this->gety());
    }

    return;
}

void jugador::posiciona(int _x, int _y) {
    x = _x;
    y = _y;
}