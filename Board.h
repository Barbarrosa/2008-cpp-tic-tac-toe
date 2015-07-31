#include "SDL/SDL.h"
#include "O.h"
#include "X.h"

#ifndef BOARD_H_
#define BOARD_H_

class Board{
	enum spot{ber,xer,oer};
	spot** board;
	SDL_Surface* screen;
	X x;
	O o;
	int clicks;
	int lineWidth;
	bool turn;
	bool isWon;
	spot xro;
	bool toWin(spot st);
	bool spotClicked(int row, int column);
	public:
	Board(SDL_Surface* surface);
	bool handleEvent(SDL_Event* event);
	bool isEmpty();
	void show();
	bool won();
	friend class AI;
};

#endif /*BOARD_H_*/
