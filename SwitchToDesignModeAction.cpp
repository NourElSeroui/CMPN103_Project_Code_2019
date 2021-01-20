#include "SwitchToDesignModeAction.h"


SwitchToDesignModeAction::~SwitchToDesignModeAction(void)
{}
SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager *pApp):Action(pApp)
{}
void SwitchToDesignModeAction::ReadActionParameters()
{
	int x, y;
	int MaxWallet=0;
	int MaxStepCount=0;
	Player * winner=NULL;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Switch to Design Mode. Are you sure to end the game ? (Y/N)..");
	string z= pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	if(z=="y" || z=="Y")
	{
		for(int i=0; i<MaxPlayerCount;i++)
		{
			if(MaxWallet <= pGrid->GetOtherPlayer(i)->GetWallet())
			{
				if(MaxWallet == pGrid->GetOtherPlayer(i)->GetWallet())
				{
					if(winner)
					{
						if(pGrid->GetOtherPlayer(i)->GetStepCount() > winner->GetStepCount())
						{
							winner = pGrid->GetOtherPlayer(i);
						}
					}
				}
				winner = pGrid->GetOtherPlayer(i);
				MaxWallet=pGrid->GetOtherPlayer(i)->GetWallet();
			}
		}
		CellPosition pos(8,0);
		for(int i=0;i<MaxPlayerCount;i++)
		{
			pGrid->GetOtherPlayer(i)->setBenefitAllCount(0);
			pGrid->UpdatePlayerCell(pGrid->GetOtherPlayer(i),pos);
			pGrid->GetOtherPlayer(i)->setHasBenefitAll(false);
			pGrid->GetOtherPlayer(i)->SetisFreezed(false);
			pGrid->GetOtherPlayer(i)->SetisPrevented(false);
			pGrid->GetOtherPlayer(i)->setMaxCount(0);
			pGrid->GetOtherPlayer(i)->SetStepCount(0);
			pGrid->GetOtherPlayer(i)->SetTurnCount(0);
			pGrid->GetOtherPlayer(i)->SetturnsToFreeze(0);
			pGrid->GetOtherPlayer(i)->SetWallet(100);
		}
		pOut->PrintMessage("Player " +to_string(winner->GetPlayernum())+ " is the winner with wallet value " +to_string(winner->GetWallet())+ ", click to continue...");
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		pOut->CreateDesignModeToolBar();
	}
	//int win = 0;
	//Player* winner = pGrid->GetOtherPlayer(0);
	//int MaxWallet = winner->GetWallet();
	//int MaxStepCount = winner->GetStepCount();
	//for (int i = 1; i < MaxPlayerCount; i++)
	//{
	//	if (pGrid->GetOtherPlayer(i)->GetWallet() > MaxWallet)
	//		winner = pGrid->GetOtherPlayer(i);
	//	else if (pGrid->GetOtherPlayer(i)->GetWallet() == MaxWallet)
	//	{
	//		if (pGrid->GetOtherPlayer(i)->GetStepCount() > MaxStepCount)
	//		{
	//			winner = pGrid->GetOtherPlayer(i);
	//			
	//		}
	//		win = i;
	//	}

	//	else winner = NULL;
	//}

	//if (winner != NULL) {
	//	pOut->PrintMessage("The winning player is player number  " + to_string(win) + "congratulations  ");
	//}
	//else if (winner == NULL)
	//{

	//	pOut->PrintMessage("no winners in the game ");

	//}

	//for (int i = 0; i < MaxPlayerCount; i++)
	//{
	//	pGrid->GetOtherPlayer(i)->SetWallet(0);
	//	pGrid->GetOtherPlayer(i)->SetStepCount(0);
	//	pGrid->GetOtherPlayer(i)->SetturnsToFreeze(0);
	//	pGrid->GetOtherPlayer(i)->SetTurnCount(0);
	//	pGrid->GetOtherPlayer(i)->setMaxCount(0);
	//	pGrid->GetOtherPlayer(i)->SetisPrevented(false);
	//	pGrid->GetOtherPlayer(i)->SetisFreezed(false);
	//	pGrid->GetOtherPlayer(i)->setHasBenefitAll(false);

	//}
	//pGrid->RemoveAllObjects();
	//pGrid->SetEndGame(true);

	}

void SwitchToDesignModeAction::Execute()
{
	
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	UI.InterfaceMode = MODE_DESIGN;
	pGrid->UpdateInterface();
	
}