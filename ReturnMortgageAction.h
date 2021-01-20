#pragma once
#include "action.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Mortgage.h"

class ReturnMortgageAction :
	public Action
{
		string whichCity;
		string decision;
		int count, times;
		int whichCard;
		int cellNum;
		Grid * pGrid;
		Input * pIn;
		Output * pOut;
		Card7 * Cairo;
		Card8 * Alex;
		Card9 * Aswan;
		Card10 * Luxor;
		Card11 * Hurghada;
		Player * CurrPlayer;

public:
	ReturnMortgageAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void NumberToString(int m);
	~ReturnMortgageAction();
};