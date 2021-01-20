#pragma once
#include "Action.h"
#include "CoinSet.h"

class AddCoinSetAction : public Action
{
	// [Action Parameters]
	//int Amount;					//1- Amount of Coins in the coinset [Read from coinset.cpp]
	CellPosition CoinSetPosition; // 2- cell position of the coinset
	// Note: These parameters should be read in ReadActionParameters()
	//int cardNumber;            // 1- the card number
public:
	AddCoinSetAction(ApplicationManager *pApp); // A Constructor
		
	virtual void ReadActionParameters(); // Reads AddCoinSetAction action parameters (cardPosition)
	
	virtual void Execute(); // Creates a new coinset Object 
	                        // and Reads the Parameters (amount)
	                        // then Sets this coinset Object to GameObject Pointer of its Cell
	virtual ~AddCoinSetAction(); // A Virtual Destructor
};