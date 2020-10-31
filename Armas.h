#pragma once
#include "allegro5/allegro.h"
class Armas
{
	private:
		ALLEGRO_BITMAP* armas;
		int x, y;
	public:
		void pinta(int sourseX, int sourceY, int x, int y);
		void setx(int _x) { x = _x; };
		void sety(int _y) { y = _y; };
		ALLEGRO_BITMAP* getBitmap() { return armas; };
		void inicia(int _x, int _y);
};

