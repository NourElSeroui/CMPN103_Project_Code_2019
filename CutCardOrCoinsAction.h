#pragma once
#include "Action.h"
#include "cellposition.h"
#include "Grid.h"
#include "Player.h"
#include"Input.h"
#include"Output.h"
#include"Card.h"
#include"CoinSet.h"
//add all cards
#include"Card1.h"
//#include"PreventCard_4.h"
//#include"FireCard_5.h"
//#include"FreezeCard_6.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Card12.h"

class CutCardOrCoinsAction :
	public Action
{
	bool f;
	CellPosition cardorcoinsposition;
	Card* pCard ;
	int cardorcoinsno;
	Input* pIn;
	Output* pOut ;
	Grid* pGrid;

public:
	CutCardOrCoinsAction(ApplicationManager* pApp);
	// Constructor

	virtual void ReadActionParameters();// Reads parameters required for action to execute 



	virtual void Execute();  // Executes action 

	virtual ~CutCardOrCoinsAction();  // Virtual Destructor
};

