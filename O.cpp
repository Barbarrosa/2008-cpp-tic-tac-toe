#include "O.h"
#include "Shared.h"
#include <cmath>

using namespace std;

O::O(){
	radius = 10;
	drawO.resize(0);
}

O::O(int r){
	radius = r;
	drawO.resize(0);
}
void O::addPlace(int x, int y){
	drawO.resize(drawO.size()+1);
	drawO[drawO.size()-1].x = x;
	drawO[drawO.size()-1].y = y;
}
void O::draw(SDL_Surface* screen){
	SDL_Rect p;
	p.w = 2;
	p.h = 2;
	for(unsigned int o = 0;o<drawO.size();o++){
		for(int i = 0;i<360;i++){
			p.x = cos(i*3.14159/180)*radius+drawO[o].x+radius;
			p.y = sin(i*3.14159/180)*radius+drawO[o].y+radius;
			SDL_FillRect(screen, &p, SDL_MapRGB(screen->format,0xFF,0xFF,0));
		}
	}
}
