#pragma once

#include "UI_Info.h"
#include "DEFS.h"
#include <fstream>
#include "Input.h"
#include "Output.h"
#include "CellPosition.h"

// forward declarations (the includes are in the cpp)
class Cell;
class GameObject;
class Ladder;
class Snake;
class CoinSet;
class Card;
class Player;
class Mortgage;

class Grid
{
	Output * pOut;   // A pointer to the Output object
	Input * pIn;     // A pointer to the Input object

	Cell * CellList[NumVerticalCells][NumHorizontalCells];  // An array of "Pointers" to All Cells of the Grid Cells
															// We make it array of pointers not objects because
															// there are NO default constructor for class Cell

	Mortgage * MortgageList[MaxMortgageCount];

	Player* PlayerList[MaxPlayerCount]; // An array of "Pointers" to the Players of the Game (MaxPlayerCount Players)
	int currPlayerNumber;   // The player number that has the turn to play 
							// currPlayerNumber is: from 0 to MaxPlayerCount - 1

	int currMortgageNumber;

	Card * Clipboard;	   // This is used in copy/cut/paste card (should be set in copy/cut and got in paste)
	CoinSet * Clipboard2;
	bool endGame;	       // A boolean indicating if the Game is ended or not (a player reaches the end cell of the grid or not)

public:

	Grid(Input * pIn, Output * pOut);	  // Gives the Grid a Pointer to the Output Object and the Input Object
										  // and makes any needed initializations

	// ========= Adding or Removing GameObjects to Cells =========

	bool AddObjectToCell(GameObject * pNewObject);		 // Adds a GameObject to the Cell of its "position" data member
	                                                     // only if the Cell does NOT already contain an object, 
	                                                     // otherwise return false and don't add

	void RemoveObjectFromCell(const CellPosition & pos); // Removes the GameObject of the Cell of the passed "position"

	void UpdatePlayerCell(Player * player, const CellPosition & newPosition); // Update the player's pCell with the CellList's Cell pointer of the "newPosition",
	                                                                          // Clears the player's circle from the previous cell
	    																	  // and  Draws it in the new cell

	void RemoveAllObjects();

	void PreventPlayer(Player* player);

	void FreezePlayer(Player* player, int no);

	bool IsOverlapping(GameObject * g);

	// ========= Setters and Getters Functions =========

	Input * GetInput() const;	// Gets a Pointer to the Input
	Output * GetOutput() const; // Gets a Pointer to the Output 
	void SetClipboard1(Card * pCard);
	Card * GetClipboard1() const;
	void SetClipboard2(CoinSet * co);
	CoinSet * GetClipboard2() const;
	void SetEndGame(bool endGame);	 // A setter for endGame data member
	bool GetEndGame() const;		 // A getter for endGame data member

	void AdvanceCurrentPlayer();     // Increments the currPlayerNum and if reaches MaxPlayerCount reset to 0 (using %)

	void setMortgageList(int whichCard,int lastOwnerNum, int i) ;
	Mortgage * getMortgageList(int i) const;

	void setMortgageNumber(int m);
	int getMortgageNumber() const;

	Player* GetOtherPlayer(int i) const;

	///TODO: add any needed setter/getter "EXCEPT" ANY setters or getters of "CellList" or "PlayerList" (Forbidden for class Responsibilities)

	// ========= Other Getters =========
	
	Player * GetCurrentPlayer() const;	// Gets a Pointer to the Current Player	                                    
	Ladder * GetNextLadder(const CellPosition & position);  // Gets a Pointer to the first Ladder after the passed "position"
	Snake * GetNextSnake(const CellPosition & position);
	CoinSet * GetNextCoinSet(const CellPosition & position);
	Card * GetNextCard(const CellPosition & position,int cardNumber);
	Card * GetNextCard(const CellPosition & position);
	//Cell * GetOtherCell(int b,int h) const;  TO BE USED.......

	// ========= User Interface Functions =========

	///TODO: add an implementation for the TODO written inside the function
	void UpdateInterface() const;		// It Updates the Grid according to the last state of the game
	                                    // In Design mode, it draws all cells/cards THEN all ladders/snakes THEN all players
	                                    // In Play mode, it only draws the player's info on the right side of the toolbar
	                                    // Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
	                                    //       and the cards/snakes/ladders positions do NOT change already in Play Mode

	void PrintErrorMessage(string msg); // Prints an error message on statusbar, Waits for mouse click then clears statusbar
									    // We added this function once here because it is used many times by other classes

	void SaveAll(ofstream &,int type);

	~Grid(); // A destructor for any needed deallcations
};