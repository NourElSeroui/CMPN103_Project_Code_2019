#pragma once
#include "Card.h"
class Card6 :
	public Card
{


private:
	// Freeze Card Parameters:
	CellPosition cFreezed; //the cell contains the player entered during gametime
	Player* pFreezed; //the player to be freezed
	Cell* cFreeze; //pointer to the cell of the cell position
	int Pnum;
	bool OE;
	int turns;

public:
	Card6(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card6 which is: OE(odd or even) and turns

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card6 on players in odd or even cells it depends
													  // by freezing them for a certain number of turns
	virtual void Save(ofstream&, int type);

	virtual void Load(ifstream&, int type);

	virtual ~Card6(); // A Virtual Destructor

};

