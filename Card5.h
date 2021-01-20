#pragma once
#include "Card.h"
class Card5 :
	public Card
{

private:
	// Fire Card Parameters:
	CellPosition cFired; //the cell contains the player entered during gametime
	Player* pFired; //the player to be fired
	Cell* cFire; //pointer to the cell of the cell position
	int Pnum;
	int v;
	int h;
public:
	Card5(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card5 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card5 on Players
													  // by Firing other players and decreamenting their wallets
	virtual void Save(ofstream&, int type);

	virtual void Load(ifstream&, int type);

	virtual ~Card5(); // A Virtual Destructor

};