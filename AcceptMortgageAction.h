#pragma once
#include "Action.h"
#include "Mortgage.h"

class AcceptMortgageAction :
	public Action
{
bool CanAccept;
int MortgageNumber;
int count;
Player * pOwner;
Input * pIn;
Output * pOut;
Grid * pGrid;
Card7 * Cairo;
Card8 * Alex;
Card9 * Aswan;
Card10 * Luxor;
Card11 * Hurghada;
string whichCity;
string decision;

public:
	AcceptMortgageAction(ApplicationManager *pApp);
	void NumberToString(int m);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AcceptMortgageAction();
};

