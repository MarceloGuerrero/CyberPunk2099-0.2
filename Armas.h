#pragma once
#include "allegro5/allegro.h"
class Armas
{
	private:
		ALLEGRO_BITMAP* arma1;
		int x, y;
		int dmg;
	public:
		void setx(int _x) { x = _x; };
		void sety(int _y) { y = _y; };
		ALLEGRO_BITMAP* getBitmap() { return arma1; };
		void pinta(int sx, int sy, int _x, int _y);
		void inicia(int _x, int _y);
};

