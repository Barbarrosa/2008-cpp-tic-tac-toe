#include "Shared.h"
#include "Board.h"

#ifndef AI_H_
#define AI_H_

class AI{
	public:
	AI();
	enum difficulty{Easy, Medium, Hard};
	void setAlgorithm(difficulty h);
	void applyAlgorithm(Board* b, int columns, int rows);
	private:
	Board::spot type;
	difficulty harder;
	void easy(Board* b, int columns, int rows);
	void medium(Board* b, int columns, int rows);
	void hard(Board* b, int columns, int rows);
};

#endif /*AI_H_*/
