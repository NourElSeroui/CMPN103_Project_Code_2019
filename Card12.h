#pragma once
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"

class Card12 :
	public Card //I don't think I need to inherit from the rest
					  //since they're all the same but with different names
{
bool exist;
int whichCard;
int cellNum;				
string z;
Card7 * Cairo;
Card8 * Alex;
Card9 * Aswan;
Card10 * Luxor;
Card11 * Hurghada;
Player * pOwner;
Input * pIn;
Output * pOut;

public:
	Card12(CellPosition & pos);
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream &,int type);
	virtual void Load(ifstream &,int type);
	~Card12();
};

