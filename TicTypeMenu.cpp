/*#include "TicTypeMenu.h"
#include "Shared.h"
#include "Board.h"



TicTypeMenu::TicTypeMenu(SDL_Surface* screeno, Board* b){
	screen = NULL;
	screen = screeno;
	if(screen == NULL)
		exit(1);
	ai = a;
	if(ai == NULL)
		exit(1);
	clicked = false;
	single.w = screen->w/2;
	single.h = screen->h/6;
	single.x = (screen->w-single.w)/2;
	single.y = (screen->h-single.h-screen->h/12)/3;
	mediumb.w = screen->w/2;
	mediumb.h = screen->h/6;
	mediumb.x = (screen->w-mediumb.w)/2;
	mediumb.y = (screen->h-mediumb.h-screen->h/12)/3*2;
	aivai.w = screen->w/2;
	aivai.h = screen->h/6;
	aivai.x = (screen->w-aivai.w)/2;
	aivai.y = (screen->h-aivai.h-screen->h/12);
	
	bool ttf = TTF_WasInit();
	font = NULL;
	text = (SDL_Surface**)malloc(sizeof(SDL_Surface*)*3);
	SDL_Color textColor = {255,255,255};
	if(!ttf){
		if(TTF_Init() == -1)
			exit(1);
	}
	font = TTF_OpenFont("Aerovias Brasil NF.ttf",30);
	if(font == NULL)
		exit(1);
	text[0] = TTF_RenderText_Solid(font, "Single Player", textColor);
	text[1] = TTF_RenderText_Solid(font, "Multiplayer", textColor);
	text[2] = TTF_RenderText_Solid(font, "AI vs AI", textColor);
	
	if(!ttf){
		TTF_Quit();
	}
}

void TicTypeMenu::makeClicked(){
	clicked = true;
	SDL_FreeSurface(text[0]);
	SDL_FreeSurface(text[1]);
	SDL_FreeSurface(text[2]);
	
}

bool TicTypeMenu::handleEvent(SDL_Event* event){
	if(clicked || event->type != SDL_MOUSEBUTTONDOWN){
		return false;
	}
	int x = event->button.x;
	int y = event->button.y;
	if(x>single.x && x<single.w+single.x){
		if(y>single.y && y<single.h+single.y){
			ai->setAlgorithm(AI::Easy);
			makeClicked();
			return true;
		}else if(y>mediumb.y && y<mediumb.h+mediumb.y){
			ai->setAlgorithm(AI::Medium);
			makeClicked();
			return true;
		}else if(y>aivai.y && y<aivai.h+aivai.y){
			ai->setAlgorithm(AI::Hard);
			makeClicked();
			return true;
		}
	}
	return false;
}

bool TicTypeMenu::isClicked(){
	return clicked;
}

void TicTypeMenu::display(){
	if(!clicked){
		SDL_FillRect(screen, &single, SDL_MapRGB(screen->format,0,0xFF,0));
		SDL_FillRect(screen, &mediumb, SDL_MapRGB(screen->format,0xFF,0xFF,0));
		SDL_FillRect(screen, &aivai, SDL_MapRGB(screen->format,0xFF,0,0));
		applySurface(single.x+(single.w-text[0]->w)/2,single.y+(single.h-text[0]->h)/2,text[0],screen,NULL);
		applySurface(multi.x+(multi.w-text[1]->w)/2,multi.y+(multi.h-text[1]->h)/2,text[1],screen,NULL);
		applySurface(aivai.x+(aivai.w-text[2]->w)/2,aivai.y+(aivai.h-text[2]->h)/2,text[2],screen,NULL);
	}
}
*/
