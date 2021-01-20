#pragma once
#include "Action.h"
class AddSnakeAction :public Action
{
private:
	CellPosition startPos;
	CellPosition endPos;
public:
	AddSnakeAction(ApplicationManager *pApp);

	virtual void ReadActionParameters(); 
	
	virtual void Execute(); 
	
	~AddSnakeAction(void);
};
