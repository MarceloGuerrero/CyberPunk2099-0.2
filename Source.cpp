#include <iostream>

using namespace std;
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "windows.h"
#include "Globales.h"
#include "inGame.h"
/* Este comentario es pitoputopato*/



void inicia_allegro(){
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_mouse();
    al_install_keyboard();
    ALLEGRO_DISPLAY *ventanita = al_create_display(PANTALLA_ANCHO, PANTALLA_ALTO);
    al_set_target_backbuffer(ventanita);
}

// programa principal
int main(){

    ///ALLEGRO_DISPLAY;
    inicia_allegro();
    const float FPS = 60;

    inGame eljuego;
    
    ///Creamos el objeto de eventos
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    //registramos los eventos de la wea
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
   
    /*jugador jugador;
    NPC guardia;
    Armas arma1;
    inGame eljuego;

    jugador.inicia(arma1);
    guardia.inicia();

    eljuego.carga_juego(jugador, guardia, arma1);*/

    
    al_start_timer(timer);

    int x =0 , y = 0 ;

    bool done = false;
    while (!done) {
        ALLEGRO_EVENT events;
        ALLEGRO_KEYBOARD_STATE keyState;
        al_wait_for_event(event_queue, &events);
        al_get_keyboard_state(&keyState);

        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
            x = events.mouse.x;
            y = events.mouse.y;

        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (events.mouse.button & 1);
            else if (events.mouse.button & 2);
        }
        //comienza el jueguin
        eljuego.menu_principal(keyState, event_queue, events, done, x, y);
        eljuego.juego_inicia(keyState, event_queue, events);
    }
    al_destroy_event_queue(event_queue);
    eljuego.~inGame();

    return 0;
}
 
