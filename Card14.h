#pragma once
#include "card.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Mortgage.h"

class Card14 :
	public Card
{
public:
	Card14(CellPosition & pos);
	Input * pIn;
	Output * pOut;
	Card7 * Cairo;
	Card8 * Alex;
	Card9 * Aswan;
	Card10 * Luxor;
	Card11 * Hurghada;
	Player * pOwner;
	int count;
	int j;
	int min;
	int whichCard;
	int times;
	int * PriceList;
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream &,int type);
	virtual void Load(ifstream &,int type);
	~Card14();
};