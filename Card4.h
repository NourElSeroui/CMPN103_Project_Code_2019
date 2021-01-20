#pragma once
#include "Card.h"
class Card4 :
	public Card
{

private:
	// Prevent Card Parameters:
	CellPosition cPrevented; //the cell contains the player entered during gametime
	Player* pPrevented; //the player to be prevented
	Cell *cP; //pointer to the cell of the cell position
	string decision;

public:
	Card4(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card4 which is: cPrevented and pPrevented

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card4 on the passed Player
													  // by Preventing the other player from rolling the dice for one turn
	virtual void Save(ofstream &, int type);

	virtual void Load(ifstream &, int type);

	virtual ~Card4(); // A Virtual Destructor
};