#include "Shared.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* dest, SDL_Rect* clip){
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, clip, dest, &offset);
}
SDL_Surface* loadImage(std::string filename){
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_Load(filename.c_str());
	optimizedImage = SDL_DisplayFormat(loadedImage);
	return optimizedImage;
}
