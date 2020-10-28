#include <iostream>

using namespace std;
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "windows.h"
#include "Globales.h"
#include "User.h"
#include "ingame.h"
/* Este comentario es pitoputopato*/

void inicia_allegro()
{
    al_init();
    al_init_image_addon();
    al_install_mouse();
    al_install_keyboard();
    ALLEGRO_DISPLAY *ventanita = al_create_display(PANTALLA_ANCHO, PANTALLA_ALTO);
    
    al_set_target_backbuffer(ventanita);

    /*while(true)al_flip_display();*/

    ///set_color_depth(32);
    ///set_gfx_mode(GFX_AUTODETECT_WINDOWED, PANTALLA_ANCHO, PANTALLA_ALTO, 0, 0);

    //buffer = al_create_bitmap(PANTALLA_ANCHO, PANTALLA_ALTO);

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
    //al_create_mouse_cursor("IMG/cursor.bmp", 0, 0);
    carga_juego();

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    //registramos los eventos de la wea
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    bool done = false;
    int x = 10, y = 10;
    int moveSpeed = 5;

    salir = false;
    bool a;
    a = false;



    loading = al_load_bitmap("IMG/intro.bmp");
    menu1 = al_load_bitmap("IMG/menu1.bmp");
    menu2 = al_load_bitmap("IMG/menu2.bmp");
    menu3 = al_load_bitmap("IMG/menu3.bmp");
    menu4 = al_load_bitmap("IMG/menu4.bmp");
    menu5 = al_load_bitmap("IMG/menu5.bmp");
    menu6 = al_load_bitmap("IMG/menu6.bmp");
    cursor = al_load_bitmap("IMG/cursor.bmp");

    int state = NULL;

    int mouseI = 0;
    int mouseD = 0;


    while (!done) {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);

        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
            x = events.mouse.x;
            y = events.mouse.y;

        }
        else if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (events.mouse.button & 1) mouseI = 1;
            else if (events.mouse.button & 2)mouseD = 1;
        }




        if (x > 970 && x < 1120 &&
            y>360 && y < 420) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(menu3, 0, 0, NULL);
            al_flip_display();
            if (events.mouse.button & 1 == 1) {

                a = true;   //funcion jugar a desarrolar
                done = false;
            }
        }

        else if (x > 970 && x < 1260 &&
            y>460 && y < 510) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(menu4, 0, 0, NULL);
            al_flip_display();
            if (events.mouse.button & 1 == 1) {

                a = true;   //funcion jugar a desarrolar
                done = false;
            }
        }
        

        else if (x > 388 && x < 921 &&
            y>408 && y < 590) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(menu2, 0, 0, NULL);
            al_flip_display();
            if (events.mouse.button & 1 == 1) {

                a = true;   //funcion jugar a desarrolar
                done = false;
            }
        }
    

        else if (x > 970 && x < 1262 &&
        y>531 && y < 594) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu5, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1 == 1) {

            a = true;   //funcion jugar a desarrolar
            done = false;
        }
        }
        else if (x > 970 && x < 1105 &&
        y>624 && y < 688) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu6, 0, 0, NULL);
        al_flip_display();
        if (events.mouse.button & 1 == 1) {

            a = true;   //funcion jugar a desarrolar
            done = false;
        }
        }
        else al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu1, 0, 0, NULL);
        al_flip_display();

            //funcion jugar a desarrolar
            //done = false;
        




        /* while (!salir)
         {
             if (contador_tiempo_juego)
             {
                 while (contador_tiempo_juego)
                 {
                     actualiza_juego();

                     contador_tiempo_juego--;
                 }

                 //al_clear_to_color(rojito);

                 //pinta_juego();

                 pintar_pantalla();

             }
             else {

                 // rest(1);
             }
             // tecla de salida
             //if (key[KEY_ESC]) salir = true;
         }*/

         ///            al_rest(10);
                     //al_destroy_display(ventanita);
        
        
    }
    ///al_destroy_event_queue(event_queue);

    return 0;
}
 
