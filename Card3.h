#pragma once
#include "Card.h"

// [ Card3 Backward Card ] Summary:
//Moves all other players backward the same number of steps that the current player just rolled (if they reach a ladder,snake,coinset take it)

class Card3 : public Card
{
int BackDiceVal;
public:
	Card3(const CellPosition & pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card3 on other Players
	                                         
	virtual ~Card3(); // A Virtual Destructor

	virtual void Save(ofstream &,int type);

	virtual void Load(ifstream &,int type);
};