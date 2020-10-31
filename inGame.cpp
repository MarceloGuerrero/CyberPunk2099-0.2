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
    

    bool choca = false;
    int px = jugador.getx();
    int py = jugador.gety();
    
}

void inGame::pinta_jugador(jugador jugador, int x, int y)
{
    jugador.pinta(x, y);
}

void inGame::pinta_fondo()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(fondo, 0, 0, NULL);
    al_flip_display();
}

void inGame::pinta_npc(NPC guardia, int x, int y) {
    guardia.pinta2(x, y);
}

void inGame::pinta_arma(Armas arma1, int sourceX, int sourceY, int x, int y) {
    arma1.pinta(sourceX, sourceY, x, y);
}

//acá vamos a declarar las colisiones
bool inGame::colision(int x, int y, int npc_x, int npc_y, int width, int height, int dir, float moveSpeed) {
    
    if (x + width < npc_x || x > npc_x + width || y + height < npc_y || y > npc_y + height) {
        return false;
    }
    else
    {
    return true;
    }
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
    
    jugador.setSpeed(3);
    int sourceX = 32, sourceY = 0, dir = sourceY;

    while (!a) {

        int x, y;

        x = jugador.getx();
        y = jugador.gety();

        actualiza_juego(jugador);
        //al_clear_to_color(vacio);
        //pinta_fondo();
        //pinta_npc(guardia, 0, 0);
        ///al_clear_to_color(vacio);
       // pinta_jugador(jugador, sourceX, dir);
        //pinta_arma(arma1, sourceX, dir);

        bool done = false;
        //jugador.teclado(jugador);
        while (!done)
        {
            jugador.teclado(arma1, keyState, event_queue, events, done, sourceX, sourceY, dir, draw, active, jugador.getSpeed());
            //aca iría el teclado en caso de explosión de código

            if(draw) {
                pinta_fondo();
                pinta_jugador(jugador, sourceX, sourceY);
                if (colision(jugador.getx(), jugador.gety(), guardia.getx(), guardia.gety(), sourceX, sourceY, dir, jugador.getSpeed())){
                    if (dir == 0) jugador.setmy(jugador.getSpeed()) ;
                    else if (dir == 1) jugador.setpx(jugador.getSpeed()) ;
                    else if (dir == 2) jugador.setmx(jugador.getSpeed()) ;
                    else if (dir == 3) jugador.setpy(jugador.getSpeed()) ;
                }
                pinta_npc(guardia, 0, 0);
                pinta_arma(arma1, sourceX, sourceY, jugador.getx(), jugador.gety());
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
            return;
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

inGame::~inGame() {
}