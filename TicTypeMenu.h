/*#include "TicMenu.h"

#ifndef TICTYPEMENU_H_
#define TICTYPEMENU_H_

class TicTypeMenu{
	SDL_Surface* screen;
	SDL_Rect single, multi, aivai;
	TTF_Font* font;
	SDL_Surface** text;
	bool clicked;
	AI* ai1, ai2;
	void makeClicked();
	TicMenu menu1, menu2;
	Board board;
	public:
	TicMenu(SDL_Surface* screeno, AI* a);
	bool handleEvent(SDL_Event* event);
	bool isClicked();
	void display();
};

#endif /*TICTYPEMENU_H_*/
