#include "jugador.h"
#include <iostream>

using namespace std;
void jugador::inicia()
{
    p1 = al_load_bitmap("IMG/allen2.bmp");
    atak = al_load_sample("IMG/2.wav");
    camina = al_load_sample("IMG/camina/23.ogg");
    camina2 = al_load_sample("IMG/camina/24.ogg");
    // inicializar vbles
    //direccion = 0;
    //animacion = 0;
    x = 620;
    y = 362;
}
void jugador::pinta(int sx, int sy) {
    al_convert_mask_to_alpha(p1, al_map_rgb(0, 0, 0));
    al_draw_bitmap_region(p1, sx, sy * 48, 32, 48, x, y, NULL);


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

void jugador::teclado(/*Armas arma1,*/ ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events,
    bool done, float& sourceX, float& sourceY, float&dir, bool draw, bool active, int moveSpeed, ALLEGRO_TIMER* timer, ALLEGRO_TIMER* frameTimer) {

    /// enum Direction { DOWN, LEFT, RIGHT, UP };

    al_wait_for_event(event_queue, &events);
    al_get_keyboard_state(&keyState);
    if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        done = true;
    }
    else if (events.type == ALLEGRO_EVENT_TIMER) {
        
            active = true;
            if (al_key_down(&keyState, ALLEGRO_KEY_S)) {
                this->y += moveSpeed;
                dir = 0;
                al_play_sample(camina, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_W)) {
                this->y -= moveSpeed;
                dir = 3;
                al_play_sample(camina2, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
                moveSpeed = 5;
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_D)) {
                this->x += moveSpeed;
                dir = 2;
                al_play_sample(camina, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_A)) {
                this->x -= moveSpeed;
                dir = 1;
                al_play_sample(camina2, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_R) && ataca == 0) {
                ataca = 1;
                //cout << ataca;
            }
            else if (al_key_down(&keyState, ALLEGRO_KEY_R) && ataca == 1) {
                ataca = 2;
                al_play_sample(atak, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                //cout << ataca;
            }
            else if (ataca == 2) ataca = 0;
            else if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
            {
                done = true;
            }
            else {
                active = false;
            }
            if (events.timer.source == frameTimer && ataca == 0) {
                if (active)sourceX += al_get_bitmap_width(this->getBitmap()) / 3;
                //sourceX += al_get_bitmap_width(arma1.getBitmap()) / 6;
                else sourceX = 32;
                if (sourceX >= al_get_bitmap_width(this->getBitmap())) sourceX = 0;
                sourceY = dir;
                /*if (sourceX = 0 && atacando) {
                    
                }*/
            }
        draw = true;
        if (draw) {
            this->setx(x);
            this->sety(y);
            /*if (ataca == 2 ) {


            }*/
            /*arma1.setx(this->getx());
            arma1.sety(this->gety());*/
        }
    }
        //return;
}

void jugador::posiciona(float _x, float _y) {
    x = _x;
    y = _y;
}

void jugador::sufre_da�o(int dmg, jugador& jugador) {

    if (!muerto)
    {
        vida -= dmg;
        //cout << "vidita" << vidaAct << endl;
        if (vida <= 0)
        {
            muerto = true;
            jugador.~jugador();
        }
    }
}

jugador::jugador() {
    vida = 1000;
}
jugador::~jugador() {

}