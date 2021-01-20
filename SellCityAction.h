#pragma once
#include "action.h"
#include "Grid.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Mortgage.h"

class SellCityAction :
	public Action
{
string whichCity;
int whichCard;
Card7 * Cairo;
Card8 * Alex;
Card9 * Aswan;
Card10 * Luxor;
Card11 * Hurghada;
public:
	SellCityAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void StringToCase();
	~SellCityAction();
};

