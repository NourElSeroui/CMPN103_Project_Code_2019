#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_COINSET,
	ADD_CARD,		// Add Card Action	
	
	///TODO: Add more action types of Design Mode
	
	COPY_CARD_OR_COINS,
	CUT_CARD_OR_COINS,
	PASTE,
	DELETEGAMEOBJECT,
	SAVEGRID,
	OPENGRID,
	TO_PLAY_MODE,	// Go to Play Mode
	EXIT,			// Exit Application
	
	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	
	///TODO: Add more action types of Play Mode

	INPUT_DICE_VALUE,
	OFFER_MORTGAGE,
	ACCEPT_MORTGAGE,
	RETURN_MORTGAGE,
	SELLCITY,
	NEWGAME,
	TO_DESIGN_MODE,	// Go to Design Mode
	EXIT_2,
	
	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};
#endif