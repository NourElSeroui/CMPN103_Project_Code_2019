#pragma once
#include <string>
#include <fstream>
#include "Action.h"
#include "Ladder.h"
#include "Snake.h"
#include "CoinSet.h"
#include "Input.h"
#include "Output.h"
#include "Card1.h"
#include "Card2.h"
#include "Card3.h"
#include "Card4.h"
#include "Card5.h"
#include "Card6.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Card12.h"
#include "Card13.h"
#include "Card14.h"
#include "Card15.h"

class OpenGridAction : public Action
{
	string file;
	Grid * pGrid;
	ifstream openFile;
	Input * pIn;
	Output * pOut;
	int countLadders;
	int countSnakes;
	int countCoinSets;
	int countCards;
	int cardNumber;
public:
	OpenGridAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~OpenGridAction();
};