#pragma once
#include "Action.h"
#include "cellposition.h"
#include "Grid.h"
#include "Player.h"
#include"CutCardOrCoinsAction.h"
#include"CopyCardOrCoinsAction.h"
#include"Input.h"
#include"Output.h"
#include"Card.h"
#include"CoinSet.h"
//add all cards
#include"Card1.h"
#include"Card2.h"
#include"Card3.h"
#include"Card4.h"
//#include"FireCard_5.h"
//#include"FreezeCard_6.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Card12.h"
#include "Card13.h"
#include "Card14.h"
#include "Card15.h"

class PasteAction :
	public Action
{
	Input* pIn;
	Output* pOut;
	Grid* pGrid;
	CellPosition cardorcoinsposition;
	Card* pCard;
public:
	PasteAction(ApplicationManager* pApp);
	// Constructor

	virtual void ReadActionParameters();// Reads parameters required for action to execute 



	virtual void Execute();  // Executes action 

	virtual ~PasteAction();  // Virtual Destructor
};

