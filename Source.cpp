#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/mouse.h"
#include "allegro5/events.h"
using namespace std;
#include "Globales.h"
#include "User.h"
#include "ingame.h"


using namespace std;


void inicia_allegro()
{
    al_init();
    al_install_keyboard();

    ///set_color_depth(32);
    ///set_gfx_mode(GFX_AUTODETECT_WINDOWED, PANTALLA_ANCHO, PANTALLA_ALTO, 0, 0);

    buffer = al_create_bitmap(PANTALLA_ANCHO, PANTALLA_ALTO);

    //FRAME_RATE = 60;//(contador_tiempo_juego);
    //LOCK_FUNCTION(inc_contador_tiempo_juego);

    // Iniciamos el limitador de FPS
    //install_int_ex(inc_contador_tiempo_juego, BPS_TO_TIMER(FRAME_RATE));
}

// programa principal
int main()
{
    ///ALLEGRO_DISPLAY;
    inicia_allegro();
    al_install_mouse();
    al_install_keyboard();
    //al_create_mouse_cursor("IMG/cursor.bmp", 0, 0);
    carga_juego();


    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    
    //registramos los eventos de la wea
    al_register_event_source(event_queue, al_get_mouse_event_source());

    bool done = false;

    int x, y;

    while (!done)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        
            if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                done = true;
        }
            else if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
                x = events.mouse.x;
                y = events.mouse.y;

            }
            else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
               /* if (events.mouse.button & 1);
                else if (events.mouse.button & 2);/
            }

    }*/
    

    bool a;

    salir = false;
    a = false;

    loading = al_load_bitmap("IMG/intro.bmp");
    menu1 = al_load_bitmap("IMG/menu1.bmp");
    menu2 = al_load_bitmap("IMG/menu2.bmp");
    menu3 = al_load_bitmap("IMG/menu3.bmp");
    menu4 = al_load_bitmap("IMG/menu4.bmp");
    menu5 = al_load_bitmap("IMG/menu5.bmp");
    menu6 = al_load_bitmap("IMG/menu6.bmp");
    cursor = al_load_bitmap("IMG/cursor.bmp");


    //loading_screen();


    while (!a) {
        if (mouse.x > 970 && mouse.x < 1120 &&
            mouse.y>360 && mouse.y < 420) {
            al_draw_bitmap_region(menu3, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);
            if (mouse.button & 1) {

                a = true;   //funcion jugar a desarrolar
            }
        }
        else if (ALLEGRO_EVENT::mouse.x > 960 && ALLEGRO_EVENT::mouse_x < 1260 &&
            ALLEGRO_EVENT::mouse.y>460 && ALLEGRO_EVENT::mouse.y < 510) {
            al_draw_bitmap_region(menu4, buffer, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);
            if (mouse_b & 1) {

                a = true;   //puntuacion  a desarrolar
            }
        }
        else if (mouse_x > 388 && mouse_x < 921 &&
            mouse_y>408 && mouse_y < 590) {
            al_draw_bitmap_region(menu2, buffer, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);
            if (mouse_b & 1) {

                a = true;   //opcion  a desarrolar
            }
        }
        else if (mouse_x > 960 && mouse_x < 1202 &&
            mouse_y>531 && mouse_y < 594) {
            al_draw_bitmap_region(menu5, buffer, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);
            if (mouse_b & 1) {

                a = true;   //opcion  a desarrolar
            }
        }
        else if (mouse_x > 960 && mouse_x < 1105 &&
            mouse_y>624 && mouse_y < 688) {

            al_draw_bitmap_region(menu6, buffer, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);
            if (mouse_b & 1) {
                a = true;
            }

        }
        else  al_draw_bitmap_region(menu1, buffer, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);

        al_draw_bitmap_region(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 11);
        al_draw_bitmap_region(buffer, screen, 0, 0, 0, 0, PANTALLA_ALTO, PANTALLA_ANCHO);

        pintar_pantalla();
        if (key[KEY_R]) a = true;

    }*/


    while (!salir)
    {
        if (contador_tiempo_juego)
        {
            while (contador_tiempo_juego)
            {
                actualiza_juego();

                contador_tiempo_juego--;
            }

            al_clear_to_color(rojito);

            pinta_juego();

            pintar_pantalla();

        }
        else {

           // rest(1);
        }
        // tecla de salida
        //if (key[KEY_ESC]) salir = true;
    }

    al_destroy_bitmap(buffer);

    return 0;
}