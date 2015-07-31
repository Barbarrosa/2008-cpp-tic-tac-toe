#include "X.h"
#include "Shared.h"

using namespace std;

X::X(){
	width = 40;
	height = 40;
	drawX.resize(0);
}

X::X(int w, int h){
	width = w;
	height = h;
	drawX.resize(0);
}
void X::addPlace(int x, int y){
	drawX.resize(drawX.size()+1);
	drawX[drawX.size()-1].x = x;
	drawX[drawX.size()-1].y = y;
	drawX[drawX.size()-1].w = width;
	drawX[drawX.size()-1].h = height;
}
void X::draw(SDL_Surface* screen){
	int w;
	SDL_Rect p;
	p.w = 1;
	p.h = 1;
	for(unsigned int i = 0;i<drawX.size();i++){
		w = 0;
		for(int h = 0;h<height+1;h++){
			if((w/(double)width) < (h/(double)height)){
				while((w/(double)width) < (h/(double)height)){
					w++;
					p.x = drawX[i].x + w;
					p.y = drawX[i].y + h;
					SDL_FillRect(screen, &p, SDL_MapRGB(screen->format,0,0,0xFF));
					p.x = drawX[i].x + width - w;
					SDL_FillRect(screen, &p, SDL_MapRGB(screen->format,0,0,0xFF));
				}
			}else{
				p.x = drawX[i].x + w;
				p.y = drawX[i].y + h;
				SDL_FillRect(screen, &p, SDL_MapRGB(screen->format,0,0,0xFF));
				p.x = drawX[i].x + width - w;
				SDL_FillRect(screen, &p, SDL_MapRGB(screen->format,0,0,0xFF));
			}
		}
	}
}
