#include "OpenGridAction.h"


OpenGridAction::OpenGridAction(ApplicationManager *pApp) : Action(pApp)
{
	pGrid = pManager->GetGrid();
	countLadders=0;
	countSnakes=0;
	countCoinSets=0;
	countCards=0;
	cardNumber=0;
}

void OpenGridAction::ReadActionParameters()
{
	pOut->PrintMessage("Enter the file name to open....");
	file=pIn->GetSrting(pOut);
	openFile.open(file+".txt");
}


void OpenGridAction::Execute()
{
	int a,b;
	CellPosition pos(8,0);
	CellPosition po(8,0);
	pIn = pGrid->GetInput();
	pOut = pGrid->GetOutput();
	pGrid = pManager->GetGrid();
	ReadActionParameters();
	if(openFile.is_open())
	{
		pOut->PrintMessage("File opened successfully. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
	}
	else
	{
		pOut->PrintMessage("File doesn't exist. (Click to continue....)");
		pIn->GetPointClicked(a,b);
		pOut->ClearStatusBar();
	}
	//IMPORTNANT : WE NEED TO ADD THE "NEW GAME" IMPLEMENTATION HERE !!!!!
	pOut->ClearGridArea();
	pOut->ClearStatusBar();
	CellPosition origin(8,0);
	CellPosition pCell;
	for(int i=0;i<4;i++)
	{
		
		pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(),origin);
		pGrid->GetCurrentPlayer()->SetWallet(100);
		pGrid->GetCurrentPlayer()->SetTurnCount(0);
		pGrid->GetCurrentPlayer()->SetStepCount(0);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->RemoveAllObjects();
	while(pGrid->GetCurrentPlayer()->GetPlayernum() !=0)
	{				
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->SetEndGame(false);
	int startCell;
	int endCell;
	openFile >> countLadders;
	if(countLadders > 0)
	{
		Ladder * l[50];
		for(int i=0;i<countLadders;i++)
		{
			openFile >> startCell >> endCell ;
			if(startCell > 0 && startCell < 99 && endCell > 0 && endCell < 99)
			{
				l[i] = new Ladder(startCell,endCell);
				pGrid->AddObjectToCell(l[i]);
			}
		}
	}
	openFile >> countSnakes;
	if(countSnakes > 0)
	{
		Snake * s[50];
		for(int i=0;i<countSnakes;i++)
		{
			openFile >> startCell >> endCell ;
			if(startCell > 0 && startCell < 99 && endCell > 0 && endCell < 99)
			{
				s[i] = new Snake(startCell,endCell);
				pGrid->AddObjectToCell(s[i]);
			}
		}
	}
	CoinSet * co;
	openFile >> countCoinSets;
	if(countCoinSets > 0)
	{
		for(int i=0;i<countCoinSets;i++)
		{
			co = new CoinSet(pos);
			co->Load(openFile,3);
			pGrid->AddObjectToCell(co);
		}
	}
	openFile >> countCards;
	if(countCards > 0)
	{
		for(int i=0;i<countCards;i++)
		{
			openFile >> cardNumber;
			switch(cardNumber)
			{
			case 1:
				Card1 * c1;
				c1=new Card1(pos);
				c1->Load(openFile,4);
				pGrid->AddObjectToCell(c1);
				break;
			case 2:
				Card2 * c2;
				c2=new Card2(pos);
				c2->Load(openFile,4);
				pGrid->AddObjectToCell(c2);
				break;
			case 3:
				Card3 * c3;
				c3=new Card3(pos);
				c3->Load(openFile,4);
				pGrid->AddObjectToCell(c3);
				break;
			case 4:
				Card4 * c4;
				c4=new Card4(pos);
				c4->Load(openFile,4);
				pGrid->AddObjectToCell(c4);
				break;
			case 5:
				Card5 * c5;
				c5=new Card5(pos);
				c5->Load(openFile,4);
				pGrid->AddObjectToCell(c5);
				break;
			case 6:
				Card6 * c6;
				c6=new Card6(pos);
				c6->Load(openFile,4);
				pGrid->AddObjectToCell(c6);
				break;
			case 7:
				Card7 * Cairo;
				Cairo=new Card7(pos);
				Cairo->Load(openFile,4);
				pGrid->AddObjectToCell(Cairo);
				break;
			case 8:
				Card8 * Alex;
				Alex=new Card8(pos);
				Alex->Load(openFile,4);
				pGrid->AddObjectToCell(Alex);
				break;
			case 9:
				Card9 * Aswan;
				Aswan=new Card9(pos);
				Aswan->Load(openFile,4);
				pGrid->AddObjectToCell(Aswan);
				break;
			case 10:
				Card10 * Luxor;
				Luxor=new Card10(pos);
				Luxor->Load(openFile,4);
				pGrid->AddObjectToCell(Luxor);
				break;
			case 11:
				Card11 * Hurghada;
				Hurghada=new Card11(pos);
				Hurghada->Load(openFile,4);
				pGrid->AddObjectToCell(Hurghada);
				break;
			case 12:
				Card12 * c12;
				c12=new Card12(pos);
				c12->Load(openFile,4);
				pGrid->AddObjectToCell(c12);
				break;
			case 13:
				Card13 * c13;
				c13=new Card13(pos);
				c13->Load(openFile,4);
				pGrid->AddObjectToCell(c13);
				break;
			case 14:
				Card14 * c14;
				c14=new Card14(pos);
				c14->Load(openFile,4);
				pGrid->AddObjectToCell(c14);
				break;
			case 15:
				Card15 * c15;
				c15=new Card15(pos);
				c15->Load(openFile,4);
				pGrid->AddObjectToCell(c15);
			default:
				break;
			}
		}
	}
	Card7 * Cairo= dynamic_cast<Card7 *>(pGrid->GetNextCard(pos,7));
	Card8 * Alex= dynamic_cast<Card8 *>(pGrid->GetNextCard(pos,8));
	Card9 * Aswan= dynamic_cast<Card9 *>(pGrid->GetNextCard(pos,9));
	Card10 * Luxor= dynamic_cast<Card10 *>(pGrid->GetNextCard(pos,10));
	Card11 * Hurghada= dynamic_cast<Card11 *>(pGrid->GetNextCard(pos,11));
	if(Cairo)
	{
		Cairo->ResetLoad();
	}
	if(Alex)
	{
		Alex->ResetLoad();
	}
	if(Aswan)
	{
		Aswan->ResetLoad();
	}
	if(Luxor)
	{
		Luxor->ResetLoad();
	}
	if(Hurghada)
	{
		Hurghada->ResetLoad();
	}
	openFile.close();
	return;
}

OpenGridAction::~OpenGridAction()
{
}