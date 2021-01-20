#include "Grid.h"

#include "Mortgage.h"
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "CoinSet.h"
#include "Card.h"
#include "Player.h"



Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Initialize Clipboard with NULL
	Clipboard=NULL;
	Clipboard2 = nullptr;
	// Initialize endGame with false

	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}
	for (int i = 0; i<MaxMortgageCount;i++)
	{
		MortgageList[i]=NULL;
	}
	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}
	currMortgageNumber=0;
	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	if(pNewObject)
	{
		CellPosition pos = pNewObject->GetPosition();
		if (pos.IsValidCell()) // Check if valid position
		{
			// Get the previous GameObject of the Cell
			GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
			if( pPrevObject)  // the cell already contains a game object
				return false; // do NOT add and return false

			// Set the game object of the Cell with the new game object
			CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
			return true; // indicating that addition is done
		}
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::RemoveAllObjects()
{
	for (int j=0;j<NumHorizontalCells;j++)
	{
		for (int i=0;i<NumVerticalCells;i++)
		{
			
			RemoveObjectFromCell(CellList[i][j]->GetCellPosition());
		}
	}
}


void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}

void Grid::PreventPlayer(Player* player) 
{
	player->SetisPrevented(true);
}

void Grid::FreezePlayer(Player* player, int no)
{
	player->SetisFreezed(true);
	player->SetturnsToFreeze(no);
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard1(Card * pCard)
{
	Clipboard = pCard;
}

Card * Grid::GetClipboard1() const
{
	return Clipboard;
}

void Grid::SetClipboard2(CoinSet * co)
{
	Clipboard2 = co;
}

CoinSet * Grid::GetClipboard2() const
{
	return Clipboard2;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if(CellList[i][j]->HasLadder())
			{
				return CellList[i][j]->HasLadder()  ;
			}


			///TODO: Check if CellList[i][j] has a ladder, if yes return it (done)
			

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake * Grid::GetNextSnake(const CellPosition & position)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if(CellList[i][j]->HasSnake())
			{
				return CellList[i][j]->HasSnake();
			}


			///TODO: Check if CellList[i][j] has a ladder, if yes return it (done)
			

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found

}

CoinSet * Grid::GetNextCoinSet(const CellPosition & position)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the card in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if(CellList[i][j]->HasCoinSet())
			{
				if(CellList[i][j]->HasCoinSet())
				{
					return CellList[i][j]->HasCoinSet();
				}
			}
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}


Card * Grid::GetNextCard(const CellPosition & position,int cardNumber)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the card in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if(CellList[i][j]->HasCard())
			{
				if(cardNumber==0)
				{
					return CellList[i][j]->HasCard();
				}
				if(CellList[i][j]->HasCard()->GetCardNumber()==cardNumber)
				{
					return CellList[i][j]->HasCard();
				}
			}
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Card * Grid::GetNextCard(const CellPosition & position)
{

	int startH = position.HCell(); 
	for (int i = position.VCell(); i >= 0; i--) 
	{
		for (int j = startH; j < NumHorizontalCells; j++) 
		{
			
			if(CellList[i][j]->HasCard())
			{
				return CellList[i][j]->HasCard();
			}
			
		}
		startH = 0; 
	}
	return NULL; 
}


void Grid::setMortgageList(int whichCard, int lastOwnerNum,int i)
{
		if(whichCard >=1 && whichCard < 6 && lastOwnerNum >=0 && lastOwnerNum <4 && i<5 && i>-1)
		{
			MortgageList[i]= new Mortgage() ;
			MortgageList[i]->setLastOwnerNum(lastOwnerNum);
			MortgageList[i]->setWhichCard(whichCard);
		}
		else
		{
			MortgageList[i]= NULL;
		}
}

Mortgage * Grid::getMortgageList(int i) const
{
 	return MortgageList[i];
}


void Grid::setMortgageNumber(int m)
{
	currMortgageNumber=m;
}

int Grid::getMortgageNumber() const
{
	return currMortgageNumber;
}

Player* Grid::GetOtherPlayer(int i) const
{
	return PlayerList[i];
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		/*for(int i = NumVerticalCells-1; i>=0; i--)
		{
			for(int j = 0; j < NumHorizontalCells;j++)
			{
				CellList[i][j]->DrawCoinSet(pOut);
			}
		}*/
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut); //Draws the CoinSet too.
			}
		}
		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}
		

		///TODO: Add the code that draws the CoinSet game objects (Done)
		
		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::SaveAll(ofstream & SaveAction,int type)
{
	if(type==1)
	{	
		CellPosition pos(1);
		int countLadders=0;
		while(GetNextLadder(pos)!=NULL)
		{
			countLadders++;
			int cellNum=GetNextLadder(pos)->GetPosition().GetCellNum()+1;
			pos = pos.GetCellPositionFromNum(cellNum);
		}
		SaveAction << countLadders << endl;
		CellPosition po(1);
		Ladder * l[50];
		for(int i=0;i<countLadders;i++)
		{
			l[i] = GetNextLadder(po);
			if(l[i])
			{
				l[i]->Save(SaveAction,type);
				int cellNum=GetNextLadder(po)->GetPosition().GetCellNum()+1;
				po = po.GetCellPositionFromNum(cellNum);
			}
		}
	}
	if(type==2)
	{
		CellPosition pos(1);
		
		int countSnakes=0;
		while(GetNextSnake(pos)!=NULL)
		{
			countSnakes++;
			int cellNum=GetNextSnake(pos)->GetPosition().GetCellNum()+1;
			pos = pos.GetCellPositionFromNum(cellNum);
		}
		SaveAction << countSnakes << endl;
		CellPosition po(1);
		Snake * s[50];
		for(int i=0;i<countSnakes;i++)
		{
			s[i] = GetNextSnake(po);
			if(s[i])
			{
				s[i]->Save(SaveAction,type);
				int cellNum=GetNextSnake(po)->GetPosition().GetCellNum()+1;
				po = po.GetCellPositionFromNum(cellNum);
			}
		}
	}
	if(type==3)
	{
		CellPosition pos(1);
		CoinSet * co[100];
		int countCoinSets=0;
		while(GetNextCoinSet(pos)!=NULL)
		{
			countCoinSets++;
			int cellNum=GetNextCoinSet(pos)->GetPosition().GetCellNum()+1;
			pos = pos.GetCellPositionFromNum(cellNum);
		}
		SaveAction << countCoinSets << endl;
		CellPosition po(1);
		for(int i=0;i<countCoinSets;i++)
		{
			co[i]=GetNextCoinSet(po);
			if(co[i])
			{
				co[i]->Save(SaveAction,type);
				int cellNum=GetNextCoinSet(po)->GetPosition().GetCellNum()+1;
				po = po.GetCellPositionFromNum(cellNum);
			}
		}
	}
	if(type==4)
	{
		int countCards=0;
		CellPosition poCard(8,0);
		Card * cards [100];
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				if(CellList[i][j]->HasCard())
				{
					cards[countCards]=CellList[i][j]->HasCard(); //GetNextCard() needs a type to return different cards (derived classes) but HasCard() returns Card * (base class)
					countCards++;
				}
			}
		}
		SaveAction << countCards << endl;
		for(int i=0;i<countCards;i++)
		{
			cards[i]->Save(SaveAction,type);
		}
	}
}

bool Grid::IsOverlapping(GameObject * GameObj)
{
	Ladder* l=dynamic_cast<Ladder*>(GameObj);
	Snake* s=dynamic_cast<Snake*>(GameObj);
	Ladder* pLadder;
    Snake* pSnake;
	for (int i=NumVerticalCells-1;i>=0;i--)
	{
		for (int j=0;j<NumHorizontalCells;j++)
		{
			 pLadder=CellList[i][j]->HasLadder();
			 pSnake=CellList[i][j]->HasSnake();
			 if(pLadder && l)
			 {
			 if(l->IsOverlapping(pLadder))
			 {
				 return true;
			 }
			 }
			 else if(pSnake && s)
			 {
				 if(s->IsOverlapping(pSnake))
				 {
					 return true;
				 }
			 }
		}
	}
     return false;

}


void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}
	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}