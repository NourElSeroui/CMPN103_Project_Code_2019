#pragma once
#include "Action.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"

class OfferMortgageAction :
	public Action
{
int times;
int LastOwnerNum;
Player * LastOwner;
Player * CurrPlayer;
bool CanMortgage;
int whichCard;
Card7 * Cairo;
Card8 * Alex;
Card9 * Aswan;
Card10 * Luxor;
Card11 * Hurghada;
Input * pIn;
Output * pOut;
Grid * pGrid;
public:
	OfferMortgageAction(ApplicationManager *pApp);
	int getWhichCard() const;
	virtual void ReadActionParameters();
	virtual void Execute();
	~OfferMortgageAction();
};
