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

    al_draw_bitmap_region(p1, sx, sy * al_get_bitmap_height(p1) / 4, al_get_bitmap_width(p1) / 3, al_get_bitmap_height(p1) / 4, x, y, NULL);
   

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

/*void player::teclado(player jugador) {
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    ALLEGRO_EVENT events;
    al_wait_for_event(event_queue, &events);
    ALLEGRO_KEYBOARD_STATE keyState;
    enum Direction { DOWN, LEFT, RIGHT, UP };
    al_get_keyboard_state(&keyState);

    bool done = false, draw = true, active = false;
    int sourceX = 32, sourceY = 0;
    int y, x, moveSpeed;
    int dir=DOWN;

    while (!done) {
        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        else if (events.type == ALLEGRO_EVENT_TIMER) {
            active = true;
            if (al_key_down(&keyState, ALLEGRO_KEY_S)) {
                y += moveSpeed;
                dir = DOWN;
            }

            else if (al_key_down(&keyState, ALLEGRO_KEY_W)) {
                y -= moveSpeed;
                dir = UP;
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_D)) {
                x += moveSpeed;
                dir = RIGHT;
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_A)) {
                x -= moveSpeed;
                dir = LEFT;
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
            sourceX += al_get_bitmap_width(p1) / 3;
        }
        else {
            sourceX = 32;
        }
        if (sourceX >= al_get_bitmap_width(p1)) {
            sourceX = 0;
        }
        sourceY = dir;
        draw = true;

        if (draw) {
            jugador.setx(x);
            jugador.sety(y);
            pinta_juego(jugador, sourceX, sourceY);
            al_flip_display();
        }

        // limites
        if (x < 0) x = 0;
        if (x > PANTALLA_ANCHO) x = PANTALLA_ANCHO;
        if (y < 0) y = 0;
        if (y > PANTALLA_ALTO)  y = PANTALLA_ALTO;
    }
}*/

void jugador::posiciona(int _x, int _y) {
    x = _x;
    y = _y;
}