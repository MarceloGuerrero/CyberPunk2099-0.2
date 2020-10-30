#pragma once
#include "allegro5/allegro.h"
class Armas
{
	private:
		ALLEGRO_BITMAP* arma1;
		int x, y;
	public:
		void pinta(int sx, int sy);
		void inicia(int _x, int _y);
};

