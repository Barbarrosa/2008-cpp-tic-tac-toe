#include "AI.h"
#include <cstdlib>
#include <vector>

using namespace std;

AI::AI(){
	
}
void AI::easy(Board* b, int columns, int rows){
	Board::spot** board = b->board;
	std::vector<int> blacklist;
	bool exit;
	bool ext1 = false;
	if(board[columns-1][rows-3] != Board::ber && board[columns-3][rows-1] != Board::ber && board[columns-3][rows-3] != Board::ber && board[columns-1][rows-1] != Board::ber){
		ext1 = true;
	}
	int randomNum;
	while(!ext1){
		randomNum = std::rand()%4+1;
		if(randomNum == 1 && board[columns-1][rows-1] == Board::ber){
			b->spotClicked(rows-1, columns-1);
			return;
		}
		else if(randomNum == 2 && board[columns-3][rows-3] == Board::ber){
			b->spotClicked(rows-3, columns-3);
			return;
		}
		else if(randomNum == 3 && board[columns-3][rows-1] == Board::ber){
			b->spotClicked(rows-1, columns-3);
			return;
		}
		else if(randomNum == 4 && board[columns-1][rows-3] == Board::ber){
			b->spotClicked(rows-3, columns-1);
			return;
		}
	}
	
	for(int col = 0;col<columns;col++){
		for(int col1 = 0;col1<rows;col1++){
			if(board[col][col1] == type){
				for(int i = col-1;i<col+1;i++){
					for(int i1 = col1-1;i1<col1+1;i1++){
						if(i>=columns || i1>=rows || i<0 || i1<0){
							continue;
						}
						if(board[i][i1] == Board::ber){
							b->spotClicked(i1, i);
							return;
						}
					}
				}
			}
		}
	}
	
	Board::spot* list = (Board::spot*)malloc(sizeof(Board::spot)*columns*rows);
	int spot = rand()%(columns*rows);
	int spotNum = 0;
	int** spots = (int**)malloc(sizeof(int*)*2);
	spots[0] = (int*)malloc(sizeof(int)*columns*rows);
	spots[1] = (int*)malloc(sizeof(int)*columns*rows);
	for(int col = 0;col<columns;col++){
		for(int col1 = 0;col1<rows;col1++){
			list[spotNum] = board[col][col1];
			spots[0][spotNum] = col;
			spots[1][spotNum] = col1;
			spotNum++;
		}
	}
	bool tooHigh;
	exit = false;
	while(exit == false){
		tooHigh = false;
		for(unsigned int i = 0;i<blacklist.size();i++){
			if(blacklist[i] == spot){
				if(spot < spotNum && !tooHigh)
					spot++;
				else{
					spot--;
					tooHigh = true;
				}
				i = 0;
			}
		}
		if(list[spot] == Board::ber){
			b->spotClicked(spots[1][spot],spots[0][spot]);
			return;
		} else if(list[spot] != Board::ber){
			blacklist.resize(blacklist.size()+1);
			blacklist[blacklist.size()-1] = spot;
			spot = rand()%(columns*rows);
		}
	}
}
void AI::hard(Board* b, int columns, int rows){
	Board::spot** board = b->board;
	bool exit = false;
	for(int i = 0;i<columns && !exit;i++){
		for(int i1 = 0;i1<rows && !exit;i1++){
			if(board[i][i1] == type){
				if(i1 > 0 && i1 < rows-1 && board[i][i1-1] == type){
					if(board[i][i1+1] == Board::ber){
						b->spotClicked(i1+1,i);
						exit = true;
					}
				}
				if(!exit && i > 0 && i < columns-1 && board[i-1][i1] == type){
					if(board[i+1][i1] == Board::ber){
						b->spotClicked(i1,i+1);
						exit = true;
					}
				}
				if(!exit && i1 > 0 && i1 < rows-1 && board[i][i1+1] == type){
					if(board[i][i1-1] == Board::ber){
						b->spotClicked(i1-1,i);
						exit = true;
					}
				}
				if(!exit && i > 0 && i < columns-1 && board[i+1][i1] == type){
					if(board[i-1][i1] == Board::ber){
						b->spotClicked(i1,i-1);
						exit = true;
					}
				}
			}
			if(!exit && i > 0 && i < columns-1 && board[i][i1] == Board::ber){
				if((board[i-1][i1] == type) && (board[i+1][i1] == type)){
					b->spotClicked(i1,i);
					exit = true;
				}
			}
			if(!exit && i1 > 0 && i1 < rows-1 && board[i][i1] == Board::ber){
				if((board[i][i1-1] == type) && (board[i][i1+1] == type)){
					b->spotClicked(i1,i);
					exit = true;
				}
			}
			if(!exit && i1 > 0 && i1 < rows-1 && i > 0 && i < columns-1){
				if(board[i-1][i1-1] == type){
					if(board[i][i1] == type){
						if(board[i+1][i1+1] == Board::ber){
							b->spotClicked(i1+1,i+1);
							exit = true;
						}
					}
					if(board[i+1][i1+1] == type){
						if(board[i][i1] == Board::ber){
							b->spotClicked(i1,i);
							exit = true;
						}
					}
				}
				if(board[i-1][i1+1] == type){
					if(board[i][i1] == type){
						if(board[i+1][i1-1] == Board::ber){
							b->spotClicked(i1-1,i+1);
							exit = true;
						}
					}
					if(board[i+1][i1-1] == type){
						if(board[i][i1] == Board::ber){
							b->spotClicked(i1,i);
							exit = true;
						}
					}
				}
				if(board[i][i1] == type){
					if(board[i+1][i1+1] == type){
						if(board[i-1][i1-1] == Board::ber){
							b->spotClicked(i1-1,i-1);
							exit = true;
						}
					}
					if(board[i-1][i1+1] == type){
						if(board[i+1][i1-1] == Board::ber){
							b->spotClicked(i1-1,i+1);
							exit = true;
						}
					}
				}
			}
		}
	}
	if(!exit)
		medium(b, columns, rows);
}
void AI::medium(Board* b, int columns, int rows){
	Board::spot** board = b->board;
	bool exit = false;
	for(int i = 0;i<columns && !exit;i++){
		for(int i1 = 0;i1<rows && !exit;i1++){
			if(!exit && board[i][i1] != Board::ber && board[i][i1] != type){
				if(!exit && i < columns-1 && i > 0){
					if(i1 == 0){
						if(!exit && board[0][1] != Board::ber && board[0][1] != type){
							if(board[0][0] == Board::ber && board[0][2] != type && board[2][0] != type){
								b->spotClicked(0,0);
								exit = true;
							}
						}
						if(!exit && board[2][1] != Board::ber && board[2][1] != type){
							if(board[2][0] == Board::ber && board[2][2] != type && board[0][0] != type){
								b->spotClicked(0,2);
								exit = true;
							}
						}
					}else if(!exit && i1 == rows-1){
						if(!exit && board[0][1] != Board::ber && board[0][1] != type){
							if(board[0][2] == Board::ber && board[2][2] != type && board[0][0] != type){
								b->spotClicked(2,0);
								exit = true;
							}
						}
						if(!exit && board[2][1] != Board::ber && board[2][1] != type){
							if(board[2][2] == Board::ber && board[2][0] != type && board[0][2] != type){
								b->spotClicked(2,2);
								exit = true;
							}
						}
					}
				}
				if(!exit && i1 > 0 && i1 < rows-1 && board[i][i1-1] != Board::ber && board[i][i1-1] != type){
					if(board[i][i1+1] == Board::ber){
						b->spotClicked(i1+1,i);
						exit = true;
					}
				}
				if(!exit && i > 0 && i < columns-1 && board[i-1][i1] != Board::ber && board[i-1][i1] != type){
					if(board[i+1][i1] == Board::ber){
						b->spotClicked(i1,i+1);
						exit = true;
					}
				}
				if(!exit && i1 > 0 && i1 < rows-1 && board[i][i1+1] != Board::ber && board[i][i1+1] != type){
					if(board[i][i1-1] == Board::ber){
						b->spotClicked(i1-1,i);
						exit = true;
					}
				}
				if(!exit && i > 0 && i < columns-1 && board[i+1][i1] != Board::ber && board[i+1][i1] != type){
					if(board[i-1][i1] == Board::ber){
						b->spotClicked(i1,i-1);
						exit = true;
					}
				}
			}
			if(!exit && i > 0 && i < columns-1 && board[i][i1] == Board::ber){
				if((board[i-1][i1] != Board::ber && board[i-1][i1] != type) && (board[i+1][i1] != Board::ber && board[i+1][i1] != type)){
					b->spotClicked(i1,i);
					exit = true;
				}
			}
			if(!exit && i1 > 0 && i1 < rows-1 && board[i][i1] == Board::ber){
				if((board[i][i1-1] != Board::ber && board[i][i1-1] != type) && (board[i][i1+1] != Board::ber && board[i][i1+1] != type)){
					b->spotClicked(i1,i);
					exit = true;
				}
			}
			if(!exit && i1 > 0 && i1 < rows-1 && i > 0 && i < columns-1){
				if(board[i-1][i1-1] != Board::ber && board[i-1][i1-1] != type){
					if(board[i][i1] != Board::ber && board[i][i1] != type){
						if(board[i+1][i1+1] == Board::ber){
							b->spotClicked(i1+1,i+1);
							exit = true;
						}
					}
					if(board[i+1][i1+1] != Board::ber && board[i+1][i1+1] != type){
						if(board[i][i1] == Board::ber){
							b->spotClicked(i1,i);
							exit = true;
						}
					}
				}
				if(board[i-1][i1+1] != Board::ber && board[i-1][i1+1] != type){
					if(board[i][i1] != Board::ber && board[i][i1] != type){
						if(board[i+1][i1-1] == Board::ber){
							b->spotClicked(i1-1,i+1);
							exit = true;
						}
					}
					if(board[i+1][i1-1] != Board::ber && board[i+1][i1-1] != type){
						if(board[i][i1] == Board::ber){
							b->spotClicked(i1,i);
							exit = true;
						}
					}
				}
				if(board[i][i1] != Board::ber && board[i][i1] != type){
					if(board[i+1][i1+1] != Board::ber && board[i+1][i1+1] != type){
						if(board[i-1][i1-1] == Board::ber){
							b->spotClicked(i1-1,i-1);
							exit = true;
						}
					}
					if(board[i+1][i1-1] != Board::ber && board[i+1][i1-1] != type){
						if(board[i-1][i1+1] == Board::ber){
							b->spotClicked(i1+1,i-1);
							exit = true;
						}
					}
				}
			}
		}
	}
	/*
	if(board[0][0] != Board::ber && board[0][0] != type){
		b->spotClicked(2,2);
		exit = true;
	}else if(board[0][2] != Board::ber && board[0][2] != type){
		b->spotClicked(0,2);
		exit = true;
	}else if(board[2][0] != Board::ber && board[2][0] != type){
		b->spotClicked(2,0);
		exit = true;
	}else if(board[2][2] != Board::ber && board[2][2] != type){
		b->spotClicked(0,0);
		exit = true;
	}
	*/
	
	if(!exit)
		easy(b, columns, rows);
}


void AI::setAlgorithm(difficulty h){
	harder = h;
}
void AI::applyAlgorithm(Board* b, int columns, int rows){
	if(b->turn)
		type = Board::xer;
	else if(!b->turn)
		type = Board::oer;
	
	if(harder == Easy)
		easy(b, columns, rows);
	else if(harder == Medium)
		medium(b, columns, rows);
	else if(harder == Hard)
		hard(b, columns, rows);
	if(b->turn == type){
		if(type == Board::oer)
			b->turn = Board::xer;
		else
			b->turn = Board::oer;
	}
}

