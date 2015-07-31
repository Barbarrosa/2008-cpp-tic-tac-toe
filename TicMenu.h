#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "AI.h"

#ifndef TICMENU_H_
#define TICMENU_H_

class TicMenu{
	SDL_Surface* screen;
	SDL_Rect easyb, mediumb, hardb;
	TTF_Font* font;
	SDL_Surface** text;
	bool clicked;
	AI* ai;
	void makeClicked();
	public:
	TicMenu(SDL_Surface* screeno, AI* a);
	bool handleEvent(SDL_Event* event);
	bool isClicked();
	void display();
};

#endif /*TICMENU_H_*/
