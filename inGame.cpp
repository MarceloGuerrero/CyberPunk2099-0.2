#include "inGame.h"
#include <iostream>


using namespace std;
/*void inGame::carga_juego(, NPC guardia, Armas arma1)
{
    ///jugador.inicia();
    //al_create_mouse_cursor("IMG/cursor.bmp", 0, 0);
    // cargamos imagenes

    /*loading = al_load_bitmap("IMG/intro.bmp");
    menu1 = al_load_bitmap("IMG/menu1.bmp");
    menu2 = al_load_bitmap("IMG/menu2.bmp");
    menu3 = al_load_bitmap("IMG/menu3.bmp");
    menu4 = al_load_bitmap("IMG/menu4.bmp");
    menu5 = al_load_bitmap("IMG/menu5.bmp");
    menu6 = al_load_bitmap("IMG/menu6.bmp");
    cursor = al_load_bitmap("IMG/cursor.bmp");


    // cargamos imagenes del primer escenario
    fondo = al_load_bitmap("IMG/Arena.bmp");

    //choque = al_load_bitmap("IMG/Arena-choque.bmp");
    //alto = al_load_bitmap("IMG/Arena-Magenta.bmp");

    

    ALLEGRO_BITMAP* p1 = jugador.getBitmap();
    ALLEGRO_BITMAP* npc = guardia.getBitmap();
    ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);
    

    /*jugador.inicia(arma1);
    guardia.inicia();
}*/

void inGame::actualiza_juego(jugador jugador)
{
    int ax, ay;
    ax = jugador.getx();
    ay = jugador.gety();
    //jugador.teclado();

    // comprobar si colisiona con el mapa
    bool choca = false;
    int px = jugador.getx();
    int py = jugador.gety();
    /* for (int ci = 0; ci < 32; ci++)
     {
         for (int cj = 16; cj < 32; cj++)
         {

             if (al_get_pixel(choque, px + ci, py + cj) == rojito) {
                 choca = true;
                 ci = 32;
                 cj = 32;
             }
             if (al_get_pixel(choque, px + ci, py + cj) == 0x00ff00) salir = true;
         }
     }
     if (choca) {
         // vuelve al estado anterior
         jugador.posiciona(ax, ay);
     }
     cout << px << endl << py << endl;

 }*/
}

void inGame::pinta_jugador(jugador jugador, int x, int y)
{
    //al_clear_to_color(al_map_rgb(0, 0, 0));
    //al_draw_bitmap(fondo, 0, 0, NULL);
    jugador.pinta(x, y);
    //al_flip_display();
}

void inGame::pinta_fondo()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(fondo, 0, 0, NULL);
    al_flip_display();
}

void inGame::pinta_npc(NPC guardia, int x, int y) {

    //al_clear_to_color(al_map_rgb(0, 0, 0));
    //al_draw_bitmap(fondo, 0, 0, NULL);
    guardia.pinta2(x, y);
    // al_flip_display();
}

void inGame::pinta_arma(Armas arma1, int x, int y) {

    arma1.pinta(x,y);

}

void inGame::juego_inicia(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue,  ALLEGRO_EVENT events){

    jugador jugador;
    NPC guardia;
    Armas arma1;

    ALLEGRO_BITMAP* p1 = jugador.getBitmap();
    ALLEGRO_BITMAP* npc = guardia.getBitmap();
    ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);


    ///this->carga_juego();

    jugador.inicia();
    int x = jugador.getx();
    int y = jugador.getx();
    arma1.inicia(x, y);
    guardia.inicia();


    bool a = false;
    bool draw = true, active = false;
    enum Direction { DOWN, LEFT, RIGHT, UP };
    float moveSpeed = 5;
    int sourceX = 32, sourceY = 0, dir = sourceY;

    while (!a) {
        actualiza_juego(jugador);
        al_clear_to_color(vacio);
        pinta_fondo();
        pinta_npc(guardia, 0, 0);
        //al_clear_to_color(vacio);
        pinta_jugador(jugador, sourceX, dir);
        pinta_arma(arma1, sourceX, dir);


        int x, y;

        x = jugador.getx();
        y = jugador.gety();


        bool done = false;
        //jugador.teclado(jugador);
        while (!done)
        {

            al_wait_for_event(event_queue, &events);
            al_get_keyboard_state(&keyState);
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
                sourceX += al_get_bitmap_width(jugador.getBitmap()) / 3;
            }
            else {
                sourceX = 32;
            }
            if (sourceX >= al_get_bitmap_width(jugador.getBitmap())) {
                sourceX = 0;
            }
            sourceY = dir;
            draw = true;

            if (draw) {
                jugador.setx(x);
                jugador.sety(y);
                pinta_fondo();
                pinta_jugador(jugador, sourceX, sourceY);
                pinta_arma(arma1, sourceX, sourceY);
                //al_flip_display();
                pinta_npc(guardia, 0, 0);
                al_flip_display();
            }

        }


    }

}

void inGame::menu_principal(ALLEGRO_KEYBOARD_STATE keyState,  ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, bool done, int x, int y) {

    if (x > 970 && x < 1120 &&
        y>360 && y < 420) {
        al_clear_to_color(vacio);
        al_draw_bitmap(menu3, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {
            this->juego_inicia(keyState, event_queue , events);
        }
    }

    else if (x > 970 && x < 1260 &&
        y>460 && y < 510) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu4, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {

            //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }


    else if (x > 388 && x < 921 &&
        y>408 && y < 590) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu2, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {

            //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }


    else if (x > 970 && x < 1262 &&
        y>531 && y < 594) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu5, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {

           //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }
    else if (x > 970 && x < 1105 &&
        y>624 && y < 688) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu6, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1) {

            //a = true;   //funcion jugar a desarrolar
            done = true;
        }
    }
    else {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu1, 0, 0, NULL);
        al_flip_display();
    }


}

/*inGame::~inGame() {



}*/