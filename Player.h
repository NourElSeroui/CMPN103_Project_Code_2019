#pragma once

#include "Grid.h"
#include "Cell.h"

class Card;
class Card7;
class Card8;
class Card9;
class Card10;
class Card11;

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	bool isPrevented;
	bool isFired;
	bool isFreezed;
	int turnsToFreeze;
	bool HasBenefitAll;
	int BenefitAllCount;
	int maxcount;
	int times;
	Player * LastCairoOwner;
	Player * LastAlexOwner;
	Player * LastAswanOwner;
	Player * LastLuxorOwner;
	Player * LastHurghadaOwner;
	Card7 * Cairo;
	Card8 * Alex;
	Card9 * Aswan;
	Card10 * Luxor;
	Card11 * Hurghada;

public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount

	int GetPlayernum() const;

	void setHasBenefitAll(bool h);

	bool getHasBenefitAll() const;

	void setBenefitAllCount(int b);

	int getBenefitAllCount() const;

	void setMaxCount(int c);
	
	void SetTurnCount(int t);

	void SetStepCount(int s);

	int getMaxCount() const;

	void SetjustRolledDiceNum(int r);

	int GetjustRolledDiceNum() const;

	void SetisPrevented(bool pr);

	bool GetisPrevented() const;

	void SetisFreezed(bool p);

	bool GetisFreezed() const;

	void SetturnsToFreeze(int tf);

	int GetturnsToFreeze() const;

	int GetStepCount() const;

	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)

};