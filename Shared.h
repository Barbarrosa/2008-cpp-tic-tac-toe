#include "SDL/SDL.h"
#include <string>

#ifndef SHARED_H_
#define SHARED_H_

SDL_Surface* loadImage(std::string filename);
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* dest, SDL_Rect* clip);

#endif /*SHARED_H_*/
