#include "AddCardAction.h"
#include "Card1.h"
#include "Card2.h"
#include "Card3.h"
#include "Card4.h"
#include "Card5.h"
#include "Card6.h"
#include "Card7.h"
#include "Card10.h"
#include "Card11.h"
#include "Card12.h"
#include "Card13.h"
#include "Card14.h"
#include "Card15.h"
#include "Input.h"
#include "Output.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	pGrid = pManager->GetGrid();
	pIn = pGrid->GetInput();
	pOut = pGrid->GetOutput();
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Enter Card Number....");
	cardNumber = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Enter Number of cell....");
	cellNum=pIn->GetInteger(pOut);
	cardPosition=cardPosition.GetCellPositionFromNum(cellNum);
	pOut->ClearStatusBar();
	// 4- Make the needed validations on the read parameters
	while(cardNumber<1 || cardNumber>15)
	{
		pOut->PrintMessage("Invalid Card Number ! Re-enter The Card Number ....");
		cardNumber = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
	}
	while(cellNum<=1 || cellNum >=99)
	{
		pOut->PrintMessage("Invalid Cell Number ! Re-enter The Cell Number ....");
		cellNum = pIn->GetInteger(pOut);
		cardPosition=cardPosition.GetCellPositionFromNum(cellNum);
		pOut->ClearStatusBar();
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters() ;
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new Card1(cardPosition);
		break;
	case 2:
		pCard = new Card2(cardPosition);
		break;
	case 3:
		pCard = new Card3(cardPosition);
		break;
	case 4:
		pCard = new Card4(cardPosition);
		break;
	case 5:
		pCard = new Card5(cardPosition);
		break;
	case 6:
		pCard = new Card6(cardPosition);
		break;
	case 7:
		pCard = new Card7(cardPosition);
		break;
	case 8:
		pCard = new Card8(cardPosition);
		break;
	case 9:
		pCard = new Card9(cardPosition);
		break;
	case 10:
		pCard = new Card10(cardPosition);
		break;
	case 11:
		pCard = new Card11(cardPosition);
		break;
	case 12:
		pCard = new Card12(cardPosition);
		break;
	case 13:
		pCard = new Card13(cardPosition);
		break;
	case 14:
		pCard = new Card14(cardPosition);
		break;
	case 15:
		pCard = new Card15(cardPosition);
		break;

		// A- Add the remaining cases
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid=pManager->GetGrid(); 	    
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);
		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if(!added)
		{
		pGrid->PrintErrorMessage("Error! Cannot be added....");
		}
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}