#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

PasteAction::~PasteAction()
{
}

void PasteAction::ReadActionParameters()
{

	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Paste Game Object: Click to continue...");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Click on the Cell to Paste the Game Object in it ...");
	cardorcoinsposition = pIn->GetCellClicked(); // Read the  parameter
	//pCard = new Card(cardorcoinsposition);

	while (cardorcoinsposition.IsValidCell() == false) //GameObjectCellPos.GetCellNum() <0 && GameObjectCellPos.GetCellNum() >99
	{
		pGrid->PrintErrorMessage("Invalid Cell. Please Re-Select a Valid Cell");
		pOut->ClearStatusBar();
		cardorcoinsposition = pIn->GetCellClicked();
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
	ReadActionParameters();
	pCard = pGrid->GetClipboard1();

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		Card1 * c1;
		Card1 * pc1;
		Card2 * c2;
		Card3 * c3;
		Card4 * c4;
		//Card5 * c5;
		//Card6 * c6;
		Card7 * c7;
		Card8 * c8;
		Card9 * c9;
		Card10 * c10;
		Card11 * c11;
		Card12 * c12;
		Card13 * c13;
		Card14 * c14;
		Card15 * c15;
		Card15 * pc15;
		switch(pCard->GetCardNumber())
		{
		case 1:
			c1 = new Card1(cardorcoinsposition);
			pc1 = dynamic_cast<Card1 * >(pCard);
			c1->SetWalletAmount(pc1->GetWalletAmount());
			break;
		case 2:
			c2 = new Card2(cardorcoinsposition);
			break;
		case 3:
			c3 = new Card3(cardorcoinsposition);
			break;
		case 4:
			c4 = new Card4(cardorcoinsposition);
			break;
	  //case 5:
		  //c5 = new Card5(cardorcoinsposition);
		  //break;
	  //case 6:
		  //c6 = new Card6(cardorcoinsposition);
		  //break;
		case 7:
			c7 = new Card7(cardorcoinsposition);
			break;
		case 8:
			c8 = new Card8(cardorcoinsposition);
			break;
		case 9:
			c9 = new Card9(cardorcoinsposition);
			break;
		
		case 10:
			c10 = new Card10(cardorcoinsposition);
			break;
		case 11:
			c11 = new Card11(cardorcoinsposition);
			break;
		case 12:
			c12 = new Card12(cardorcoinsposition);
			break;
		case 13:
			c13 = new Card13(cardorcoinsposition);
			break;
		case 14:
			c14 = new Card14(cardorcoinsposition);
			break;
		case 15:
			c15 = new Card15(cardorcoinsposition);
			pc15 = dynamic_cast<Card15 * >(pCard);
		    c15->setInputTurns(pc15->getInputTurns());
			break;
		default:
			break;
		}
		Grid* pGrid = pManager->GetGrid();
		bool Added = pGrid->AddObjectToCell(pCard);


		if (!Added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}

	}

}

