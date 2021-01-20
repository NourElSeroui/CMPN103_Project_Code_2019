#pragma once
#include "Action.h"

class InputDiceValueAction : public Action
{
private:
	int DiceValue; //inserted by user
public:
	InputDiceValueAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValueAction(void);
};