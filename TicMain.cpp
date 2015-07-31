#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "Shared.h"
#include "Board.h"
#include "AI.h"
#include "TicMenu.h"


const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;
const int SCREEN_BPP = 32;

SDL_Surface* screen = NULL;
SDL_Surface* background = NULL;
SDL_Event event;

bool init(){
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return false;
	if(TTF_Init() == -1)
		return false;
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
	if(screen == NULL)
		return false;
	background = loadImage("background.png");
	if(background == NULL)
		return false;
	SDL_WM_SetCaption("Tic Tac Toe",NULL);
	return true;
}
void cleanup(){
	SDL_FreeSurface(background);
	SDL_FreeSurface(screen);
	TTF_Quit();
	SDL_Quit();
}
int main(int argc, char** argv){
	if(!init())
		return 1;
	Board board = Board(screen);
	AI ai = AI();
	TicMenu menu = TicMenu(screen, &ai);
	applySurface(0,0,background,screen, NULL);
	board.show();
	menu.display();
	if(SDL_Flip(screen) == -1)
		return 1;
	bool quit = false;
	int firstgo = 0;
	while(!quit){
		if(SDL_WaitEvent(&event)){
			if(event.type == SDL_QUIT)
				quit = true;
			if(event.type == SDL_MOUSEBUTTONDOWN)
				if(!menu.isClicked()){
					if(menu.handleEvent(&event)){
						firstgo = rand()%2;
						applySurface(0,0,background,screen, NULL);
						board.show();
						if(SDL_Flip(screen) == -1)
							return 1;
						if(firstgo == 0){
								SDL_Delay(100);
								ai.applyAlgorithm(&board,3,3);
								board.show();
								if(SDL_Flip(screen) == -1)
									return 1;
							}
					}
				} 
				else{
					if(board.won()){
						board = Board(screen);
						menu = TicMenu(screen, &ai);
						applySurface(0,0,background,screen, NULL);
						board.show();
						menu.display();
						if(SDL_Flip(screen) == -1)
								return 1;
					}
					else{
							if(board.handleEvent(&event)){
								board.show();
								if(SDL_Flip(screen) == -1)
									return 1;
								SDL_Delay(100);
								if(!board.won()){
									ai.applyAlgorithm(&board,3,3);
								}
								board.show();
								if(SDL_Flip(screen) == -1)
									return 1;
							}
					}
				}
		}
		
		
	}
	cleanup();
}
