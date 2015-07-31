#include <vector>
#include "SDL/SDL.h"

#ifndef O_H_
#define O_H_

class O{
	int radius;
	std::vector<SDL_Rect> drawO;
	
	public:
	O();
	O(int r);
	void addPlace(int x, int y);
	void draw(SDL_Surface* screen);
};

#endif /*O_H_*/
