#include "SDL/SDL.h"
#include <vector>

#ifndef X_H_
#define X_H_

class X{
	int width, height;
	std::vector<SDL_Rect> drawX;
	
	public:
	X();
	X(int w, int h);
	void addPlace(int x, int y);
	void draw(SDL_Surface* screen);
};

#endif /*X_H_*/
