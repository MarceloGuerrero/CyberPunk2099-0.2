#pragma once
#ifndef INGAME_H_INCLUDED
#define INGAME_H_INCLUDED
//#include "allegro5/allegro.h"
using namespace std;


///declaramos los triggers
ALLEGRO_BITMAP* fondo;
ALLEGRO_BITMAP* choque;
ALLEGRO_BITMAP* alto;

ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);

bool desplaza;
/*
void carga_juego();
void actualiza_juego(player jugador);
void pinta_juego(player jugador);
*/
// carga todo lo necesario antes de empezar el juego
void carga_juego()
{
    ///jugador.inicia();
    // cargamos imagenes del primer escenario
    fondo = al_load_bitmap("IMG/Arena.bmp");
    choque = al_load_bitmap("IMG/Arena-choque.bmp");
    alto = al_load_bitmap("IMG/Arena-Magenta.bmp");
}


// actualiza el estado del juego
void actualiza_juego(player jugador)
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

// Se encarga de pintar todo sobre el buffer
void pinta_juego(player jugador, int x, int y)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(fondo, 0, 0, NULL);
    jugador.pinta(x,y);
    al_flip_display();
}


/*class BMPS :BITMAP {

public:
    void loading_screen();


};


void loading_screen() {

    bool e;


    e = false;


    while (!e) {

        al_draw_bitmap(loading, buffer, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO);
        pintar_pantalla();
        if (key[KEY_E]) e = true;

    }
}*/

#endif // INGAME_H_INCLUDED
