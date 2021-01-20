#include "Input.h"
#include "Output.h"
#include <iostream>
#include <string>
using namespace std;
//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW) 
{
	pWind = pW; // point to the passed window
}
////////////////////////////////////////////////////////////////////////////////////////// 
void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x,y); // Note: x and y of WaitMouseClick are sent by reference
}
////////////////////////////////////////////////////////////////////////////////////////// 
string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if(Key == 13 )	// ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}
////////////////////////////////////////////////////////////////////////////////////////// 
int Input::GetInteger(Output *pO) const 
{
	//DONE
	///TODO: implement the GetInteger function as described in Input.h file 
	//       using function GetString() defined above and function stoi()
	
	string s=GetSrting(pO);
	int i=stoi(s);
	//int i=stoi(GetSrting(pO));
	
	// Note: stoi(s) converts string s into its equivalent integer (for example, "55" is converted to 55)
	
	return i; // this line should be changed with your implementation
	//	OR return stoi(GetSrting(p0))
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{	
	// Reads a user click and map it to its corresponding ActionType
	int x = -1, y = -1;
	GetPointClicked(x, y); 

	//  ============ GUI in the Design mode ============
	if ( UI.InterfaceMode == MODE_DESIGN )	
	{
		// [1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight) 
		{	
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				//TODO: Add cases for the other items of Design Mode
			case ITM_ADD_LADDER: return ADD_LADDER;
			case ITM_ADD_SNAKE: return ADD_SNAKE;
			case ITM_ADD_COINSET: return ADD_COINSET;
			case ITM_ADD_CARD: return ADD_CARD;
			case ITM_COPY_CARD_OR_COINS: return COPY_CARD_OR_COINS;
			case ITM_CUT_CARD_OR_COINS: return CUT_CARD_OR_COINS;
			case ITM_PASTE_CARD_OR_COINS: return PASTE;
			case ITM_DELETE_GAME_OBJECT: return DELETEGAMEOBJECT ;
			case ITM_SAVE_GRID : return SAVEGRID ;
			case ITM_OPEN_GRID: return OPENGRID ;
			case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY_MODE;	
			case ITM_EXIT: return EXIT;
			// Note compiler get confused between 2 exit so change one of their name
			//////////////case ITM_EDIT_CARD:return EDIT_CARD;
			
			default: return EMPTY;	// A click on empty place in toolbar
			}
		}
		// [2] User clicks on the grid area
		if ( (y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;	
		}

		// [3] User clicks on the status bar
		return STATUS;
	}
	// ============ GUI in the Play mode ============
	else if ( UI.InterfaceMode == MODE_PLAY )	
	{
		///TODO:
		// perform checks similar to Design mode checks above for the Play Mode
		// and return the corresponding ActionType
		
		// [1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight) 
		{	
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			//TODO: Add cases for the other items of Design Mode
			case ITM_ROLL_DICE: return ROLL_DICE;
			case ITM_INPUT_DICE_VALUE: return INPUT_DICE_VALUE;
			case ITM_OFFER_MORTGAGE: return OFFER_MORTGAGE;
			case ITM_ACCEPT_MORTGAGE: return ACCEPT_MORTGAGE;
			case ITM_RETURN_MORTGAGE: return RETURN_MORTGAGE;
			case ITM_SELLCITY: return SELLCITY;
			case ITM_NEWGAME: return NEWGAME;
			case ITM_SWITCH_TO_DESIGN_MODE: return TO_DESIGN_MODE;
			case ITM_EXIT_2: return EXIT_2;

			default: return EMPTY;	// A click on empty place in toolbar
			}
		}
		///////////////////////////// this should be commented???
			// [2] User clicks on the grid area
		if ( (y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;	
		}
		// [3] User clicks on the status bar
		return STATUS;
		}															
		//return TO_DESIGN_MODE;	// just for now ==> This should be updated
}
////////////////////////////////////////////////////////////////////////////////////////// 
CellPosition Input::GetCellClicked() const
{
	// Wait for a Mouse Click and Gets the CellPosition of it (VCell and HCell)
	 // This function is needed only in Design Mode
	 // If the click is NOT on a cellposition, (-1,-1) is returned
	 // This function is like GetPointClicked but returns Cell Position NOT Real Coordinates
	int x,y;
	pWind->WaitMouseClick(x,y);// Get the coordinates of the user click
	
	CellPosition cellPos;

	if ( UI.InterfaceMode == MODE_DESIGN || UI.InterfaceMode == MODE_PLAY )	
	{
		if ( y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight)) // y>=55 && y<= 610-60 (550)
		{
			///TODO: SetHCell and SetVCell of the object cellPost appropriately
			//       using the coordinates x, y and the appropriate variables of the UI_Info Object (UI)
			cellPos.SetHCell(x/UI.CellWidth); // 0/110=0, 110/110 =1 , 220/110 =2 ....etc
			cellPos.SetVCell((y/UI.CellHeight)-1); // 55/55=1-1=0,110/55=2-1=1, .....550/55=10-1=9
													// or( y-UI.ToolBarHeight)/UI.CellHeight
		}
		//else
			//return -1;
	}
	return cellPos;
}
////////////////////////////////////////////////////////////////////////////////////////// 