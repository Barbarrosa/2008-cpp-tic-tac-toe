#include "TicMenu.h"
#include "Shared.h"



TicMenu::TicMenu(SDL_Surface* screeno, AI* a){
	screen = NULL;
	screen = screeno;
	if(screen == NULL)
		exit(1);
	ai = a;
	if(ai == NULL)
		exit(1);
	clicked = false;
	easyb.w = screen->w/2;
	easyb.h = screen->h/6;
	easyb.x = (screen->w-easyb.w)/2;
	easyb.y = (screen->h-easyb.h-screen->h/12)/3;
	mediumb.w = screen->w/2;
	mediumb.h = screen->h/6;
	mediumb.x = (screen->w-mediumb.w)/2;
	mediumb.y = (screen->h-mediumb.h-screen->h/12)/3*2;
	hardb.w = screen->w/2;
	hardb.h = screen->h/6;
	hardb.x = (screen->w-hardb.w)/2;
	hardb.y = (screen->h-hardb.h-screen->h/12);
	
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
	text[0] = TTF_RenderText_Solid(font, "Easy", textColor);
	text[1] = TTF_RenderText_Solid(font, "Medium", textColor);
	text[2] = TTF_RenderText_Solid(font, "Hard", textColor);
	
	if(!ttf){
		TTF_Quit();
	}
}

void TicMenu::makeClicked(){
	clicked = true;
	SDL_FreeSurface(text[0]);
	SDL_FreeSurface(text[1]);
	SDL_FreeSurface(text[2]);
	
}

bool TicMenu::handleEvent(SDL_Event* event){
	if(clicked || event->type != SDL_MOUSEBUTTONDOWN){
		return false;
	}
	int x = event->button.x;
	int y = event->button.y;
	if(x>easyb.x && x<easyb.w+easyb.x){
		if(y>easyb.y && y<easyb.h+easyb.y){
			ai->setAlgorithm(AI::Easy);
			makeClicked();
			return true;
		}else if(y>mediumb.y && y<mediumb.h+mediumb.y){
			ai->setAlgorithm(AI::Medium);
			makeClicked();
			return true;
		}else if(y>hardb.y && y<hardb.h+hardb.y){
			ai->setAlgorithm(AI::Hard);
			makeClicked();
			return true;
		}
	}
	return false;
}

bool TicMenu::isClicked(){
	return clicked;
}

void TicMenu::display(){
	if(!clicked){
		SDL_FillRect(screen, &easyb, SDL_MapRGB(screen->format,0,0xFF,0));
		SDL_FillRect(screen, &mediumb, SDL_MapRGB(screen->format,0xFF,0xFF,0));
		SDL_FillRect(screen, &hardb, SDL_MapRGB(screen->format,0xFF,0,0));
		applySurface(easyb.x+(easyb.w-text[0]->w)/2,easyb.y+(easyb.h-text[0]->h)/2,text[0],screen,NULL);
		applySurface(mediumb.x+(mediumb.w-text[1]->w)/2,mediumb.y+(mediumb.h-text[1]->h)/2,text[1],screen,NULL);
		applySurface(hardb.x+(hardb.w-text[2]->w)/2,hardb.y+(hardb.h-text[2]->h)/2,text[2],screen,NULL);
	}
}

