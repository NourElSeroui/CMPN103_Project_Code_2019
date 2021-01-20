#pragma once
#include <string>
#include <fstream>
#include "Input.h"
#include "Output.h"
#include "Action.h"
#include "Grid.h"

class SaveGridAction : public Action
{
	Input * pIn;
	ofstream save;
	Output * pOut;
	string file;
	Grid * pGrid;
public: 
	SaveGridAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SaveGridAction();
};

