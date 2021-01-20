#pragma once
#include "Action.h"
#include "cellposition.h"
#include "Grid.h"
#include "Player.h"
#include"Input.h"
#include"Output.h"
#include"CoinSet.h"
//add all cards
#include"Card1.h"
#include"Card2.h"
#include"Card3.h"
#include"Card4.h"
#include"Card5.h"
#include"Card6.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Card12.h"

class CopyCardOrCoinsAction :
	public Action
{
	bool f;
	CellPosition cardorcoinsposition;
	Card* pCard;
	int cardorcoinsno;
	Input* pIn;
	Output* pOut;
	Grid* pGrid;

public:
	CopyCardOrCoinsAction(ApplicationManager* pApp);
	// Constructor

	virtual void ReadActionParameters();// Reads parameters required for action to execute 



	virtual void Execute();  // Executes action 

	virtual ~CopyCardOrCoinsAction();  // Virtual Destructor
};