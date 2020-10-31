#pragma once
#include "NPC.h"
#include "jugador.h"
/*#ifndef INGAME_H_INCLUDED
#define INGAME_H_INCLUDED*/
//#include "allegro5/allegro.h"
//ALLEGRO_BITMAP* choque;
//ALLEGRO_BITMAP* alto;

class inGame {
    private:
        //ALLEGRO_BITMAP* fondo;
        ALLEGRO_BITMAP* loading = al_load_bitmap("IMG/intro.bmp");
        ALLEGRO_BITMAP* menu1 = al_load_bitmap("IMG/menu1.bmp");
        ALLEGRO_BITMAP* menu2 = al_load_bitmap("IMG/menu2.bmp");
        ALLEGRO_BITMAP* menu3 = al_load_bitmap("IMG/menu3.bmp");
        ALLEGRO_BITMAP* menu4 = al_load_bitmap("IMG/menu4.bmp");
        ALLEGRO_BITMAP* menu5 = al_load_bitmap("IMG/menu5.bmp");
        ALLEGRO_BITMAP* menu6 = al_load_bitmap("IMG/menu6.bmp");
        ALLEGRO_BITMAP* cursor = al_load_bitmap("IMG/cursor.bmp");
        ALLEGRO_COLOR vacio = al_map_rgb(0, 0, 0);
    public:
        int encima, debajo, izquierda, derecha;
        ALLEGRO_BITMAP* fondo = al_load_bitmap("IMG/Arena.bmp");
        ALLEGRO_COLOR rojito = al_map_rgb(255, 0, 0);
        void pinta_fondo();
        void pinta_jugador(jugador jugador, int x, int y);
        void pinta_npc(NPC guardia, int x, int y);
        void pinta_arma(Armas arma1, int sourceX, int sourceY, int x, int y);
        //void carga_juego(jugador jugador, NPC guardia, Armas arma1);
        //void carga_juego(jugador jugador, NPC guardia, Armas arma1);
        void actualiza_juego(jugador jugador);
        void juego_inicia(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events);
        void menu_principal(ALLEGRO_KEYBOARD_STATE keyState, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_EVENT events, bool done, int x, int y);
        bool colision( int x, int y, int npc_x, int npc_y, int width, int height, int dir, float moveSpeed);
        ~inGame();
};
