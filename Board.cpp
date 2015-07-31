#include "Board.h"
#include <cstdlib>
#include <iostream>
#include "Shared.h"
#include "SDL/SDL_ttf.h"

using namespace std;

Board::Board(SDL_Surface* surface){
	screen = surface;
	clicks = 0;
	lineWidth = 5;
	xro = ber;
	x = X(screen->w/4,screen->h/4);
	if(screen->w > screen->h)
		o = O(screen->h/7);
	else
		o = O(screen->w/7);
	turn = true;
	isWon = false;
	board = (spot**)malloc(sizeof(spot*)*3);
	for(int i = 0;i<3;i++){
		board[i] = (spot*)malloc(sizeof(spot)*3);
		for(int i1 = 0;i1<3;i1++)
			board[i][i1] = ber;
	}
}
//0,1,2 for row or column
bool Board::spotClicked(int row, int column){
	if(!isWon){
		int xa, y;
		xa = screen->w/3*column+lineWidth*2;
		y = screen->h/3*row+lineWidth*2;
		if(board[column][row] == ber){
			clicks++;
			if(turn && !toWin(oer)){
				x.addPlace(xa,y);
				board[column][row] = xer;
				turn = false;
				isWon = toWin(xer);
				if(isWon)
					xro = xer;
			} else if(!toWin(xer)){
				o.addPlace(xa,y);
				board[column][row] = oer;
				turn = true;
				isWon = toWin(oer);
				if(isWon)
					xro = oer;
			}
			if(clicks == 9){
				isWon = true;
			}
			return true;
		}
		return false;
	}
	return false;
}

bool Board::handleEvent(SDL_Event* event){
	if(event->type != SDL_MOUSEBUTTONDOWN)
		return false;
	int x = event->button.x;
	int y = event->button.y;
	if(x > 0 && x < screen->w/3){
		if(y > 0 && y < screen->h/3)
			return spotClicked(0, 0);
		else if(y > screen->h/3 && y < screen->h/3*2)
			return spotClicked(1, 0);
		else if(y > screen->h/3*2 && y < screen->h)
			return spotClicked(2, 0);
	} else if(x > screen->w/3 && x < screen->w/3*2){
		if(y > 0 && y < screen->h/3)
			return spotClicked(0, 1);
		else if(y > screen->h/3 && y < screen->h/3*2)
			return spotClicked(1, 1);
		else if(y > screen->h/3*2 && y < screen->h)
			return spotClicked(2, 1);
	} else if(x > screen->w/3*2 && x < screen->w){
		if(y > 0 && y < screen->h/3)
			return spotClicked(0, 2);
		else if(y > screen->h/3 && y < screen->h/3*2)
			return spotClicked(1, 2);
		else if(y > screen->h/3*2 && y < screen->h)
			return spotClicked(2, 2);
	}
	return false;
}

bool Board::toWin(spot st){
	if(board[0][0] == st){
		if(board[1][1] == st){
			if(board[2][2] == st)
				return true;
		}
		if(board[0][1] == st){
			if(board[0][2] == st)
				return true;
		}
		if(board[1][0] == st){
			if(board[2][0] == st)
				return true;
		}
	}
	if(board[1][1] == st){
		if(board[0][2] == st){
			if(board[2][0] == st)
				return true;
		}
		if(board[1][0] == st){
			if(board[1][2] == st)
				return true;
		}
		if(board[0][1] == st){
			if(board[2][1] == st)
				return true;
		}
	}
	if(board[2][2] == st){
		if(board[2][0] == st){
			if(board[2][1] == st)
				return true;
		}
		if(board[0][2] == st){
			if(board[1][2] == st)
				return true;
		}
	}
	return false;
}

void Board::show(){
	SDL_Rect v;
	v.x = screen->w/3;
	v.y = 0;
	v.w = lineWidth;
	v.h = screen->h;
	SDL_FillRect(screen, &v,SDL_MapRGB(screen->format, 0xFF,0xFF,0xFF));
	v.x = screen->w/3*2;
	SDL_FillRect(screen, &v,SDL_MapRGB(screen->format, 0xFF,0xFF,0xFF));
	
	v.x = 0;
	v.y = screen->h/3;
	v.w = screen->w;
	v.h = lineWidth;
	SDL_FillRect(screen, &v,SDL_MapRGB(screen->format, 0xFF,0xFF,0xFF));
	v.y = screen->h/3*2;
	SDL_FillRect(screen, &v,SDL_MapRGB(screen->format, 0xFF,0xFF,0xFF));
	
	x.draw(screen);
	o.draw(screen);
	bool ttf = TTF_WasInit();
	if(!ttf)
		if(TTF_Init() == -1)
			exit(0);
	if(isWon){
		TTF_Font* font = TTF_OpenFont("Aerovias Brasil NF.ttf", 50);
		SDL_Color col = {255,255,255};
		SDL_Surface* text = NULL;
		switch(xro){
			case ber:text = TTF_RenderText_Solid(font, "Game Over", col);break;
			case xer:text = TTF_RenderText_Solid(font, "X wins", col);break;
			case oer:text = TTF_RenderText_Solid(font, "O wins", col);break;
		}
		
		applySurface((screen->w-text->w)/2,(screen->h-text->h)/2, text,screen,NULL);
		TTF_CloseFont(font);
	}
	if(!ttf)
		TTF_Quit();
	
}
bool Board::won(){
	return isWon;
}

bool Board::isEmpty(){
	for(int row = 0;row<3;row++){
		for(int col = 0;col<3;col++){
			if(board[row][col] != ber)
				return false;
		}
	}
	return true;
}
