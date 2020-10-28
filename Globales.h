#pragma once
#ifndef GLOBALES_H_INCLUDED
#define GLOBALES_H_INCLUDED
//#include "allegro5/allegro.h"

// Ancho y alto de la pantalla
const int PANTALLA_ANCHO = 1280;
const int PANTALLA_ALTO = 720;
const int menuP_ANCHO = 631;
const int menuP_ALTO = 469;

// En este BITMAP dibujaremos todo
ALLEGRO_BITMAP* buffer;
ALLEGRO_BITMAP* loading, * menu1, * menu2, * menu3, * menu4, * menu5, * menu6, * cursor;
ALLEGRO_BITMAP* menu;

// controla el bucle principal
bool salir;

// Variable usada para la velocidad
//volatile unsigned int contador_tiempo_juego = 0;

// Indica los FPS
const int FRAME_RATE = 30;

const int desplazamiento = 120 / FRAME_RATE;

// es el espacio en pixel que recorre el jugador al andar
//const int desplazamiento=4;

// Copiar el buffer a la pantalla del juego (screen)
void pintar_pantalla()
{
    al_draw_bitmap_region(buffer, 0, 0, 0, 0, PANTALLA_ANCHO, PANTALLA_ALTO, ALLEGRO_FLIP_HORIZONTAL);
}

// Función para controlar la velocidad
volatile unsigned int tiempo_total = 0;

/*void inc_contador_tiempo_juego()
{
    contador_tiempo_juego++;
    tiempo_total++;
}
END_OF_FUNCTION(inc_contador_tiempo_juego);*/







#endif // GLOBALES_H_INCLUDED