#include "Player.h"

#include "GameObject.h"

#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum>=0 && playerNum<=3?playerNum:-1)
{
	if(pCell!=NULL)
	{
		this->pCell = pCell;
		this->turnCount = 0;
		this->HasBenefitAll = false;
		this->BenefitAllCount = 0;
		this->maxcount = 0;
		this->times = 0;
		this->LastCairoOwner = NULL;
		this->LastAlexOwner = NULL;
		this->LastAswanOwner = NULL;
		this->LastLuxorOwner = NULL;
		this->LastHurghadaOwner = NULL;
	}
	// Make all the needed initialization or validations (done)
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if(wallet>=0)
	{
		this->wallet = wallet;
		// Make any needed validations (done)
	}
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetPlayernum() const
{
	return playerNum;
}

void Player::setHasBenefitAll(bool h)
{
	HasBenefitAll=h;
}

bool Player::getHasBenefitAll() const
{
	return HasBenefitAll;
}

void Player::setBenefitAllCount(int b)
{
	BenefitAllCount = b;
}

int Player::getBenefitAllCount() const
{
	return BenefitAllCount;
}

void Player::setMaxCount(int c)
{
	maxcount= c;
}

int Player::getMaxCount() const
{
	return maxcount;
}

void Player::SetTurnCount(int t)
{
	turnCount=t;
}

void Player::SetStepCount(int s)
{
	stepCount=s;
}

void Player::SetjustRolledDiceNum(int r)
{
	if (r>0 && r<7) // valid for dice number 1,2,3,4,5,6 only
		justRolledDiceNum=r;
	else 
		justRolledDiceNum=0;
}
int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}
void Player::SetisPrevented(bool pr)
{
	isPrevented = pr;
}
bool Player:: GetisPrevented() const 
{
	return isPrevented;
}
void Player::SetisFreezed(bool p)
{
		isFreezed = p;
}
bool Player::GetisFreezed() const 
{
	return isFreezed;
}
void Player::SetturnsToFreeze(int tf)
{
	turnsToFreeze = tf;
}
int Player::GetturnsToFreeze() const
{ 
	return turnsToFreeze;
}

int Player::GetStepCount() const
{
	return stepCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor);

	///TODO: use the appropriate output function to draw the player with "playerColor" (done)

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor);
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it) (done)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once (done)
	turnCount++;
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move) (done)
	if(turnCount==3)
	{
		wallet = wallet + ( 10 * diceNumber );
		turnCount=0;
		return ;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber (done)
	justRolledDiceNum = diceNumber;	
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos" (done)
	CellPosition pos = pCell->GetCellPosition();
	pos.AddCellNum(diceNumber);
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	if(diceNumber>0)
	{
		pGrid->UpdatePlayerCell((pGrid->GetCurrentPlayer()),pos);
	}
	else
	{
		pGrid->UpdatePlayerCell(this,pos);
	}
	// 6- Apply() the game object of the reached cell (if any) (awaiting game objects from the others) (done)
	if(pCell->GetGameObject() && diceNumber != 0)
    {
        pCell->GetGameObject()->Apply(pGrid,this);
    }
	//===============================================================
	//                   EXTRA (Has BenefitAllCard)
	//===============================================================
	int a,b;
	CellPosition poCard(8,0);
	Cairo = dynamic_cast<Card7 *>(pGrid->GetNextCard(poCard,7));
	Alex= dynamic_cast<Card8 *>(pGrid->GetNextCard(poCard,8));
	Aswan= dynamic_cast<Card9 *>(pGrid->GetNextCard(poCard,9));
	Luxor= dynamic_cast<Card10 *>(pGrid->GetNextCard(poCard,10));
	Hurghada= dynamic_cast<Card11 *>(pGrid->GetNextCard(poCard,11));
	if(HasBenefitAll)
	{
		BenefitAllCount++;
		if(BenefitAllCount == maxcount+1)
		{
			HasBenefitAll = false;
			BenefitAllCount=0;
			times=0;
			pGrid->GetOutput()->PrintMessage("Player : " +to_string(this->GetPlayernum())+ " No Longer Benefits From All Bought Cities. (Click to continue....)");
			pGrid->GetInput()->GetPointClicked(a,b);
			pGrid->GetOutput()->ClearStatusBar();
			if(Cairo && Cairo->GetBought())
			{
				Cairo->SetCityOwner(LastCairoOwner);
				LastCairoOwner = NULL;
			}
			if(Alex && Alex->GetBought())
			{
				Alex->SetCityOwner(LastAlexOwner);
				LastAlexOwner = NULL;
			}
			if(Aswan && Aswan->GetBought())
			{
				Aswan->SetCityOwner(LastAswanOwner);
				LastAswanOwner = NULL;
			}
			if(Luxor && Luxor->GetBought())
			{
				Luxor->SetCityOwner(LastLuxorOwner);
				LastLuxorOwner = NULL;
			}
			if(Hurghada && Hurghada->GetBought())
			{
				Hurghada->SetCityOwner(LastHurghadaOwner);
				LastHurghadaOwner = NULL;
			}
		}
		else
		{
			if(times != 1)
			{
				if(Cairo && Cairo->GetBought())
				{
					LastCairoOwner = Cairo->getPlayer();
				}
				if(Alex && Alex->GetBought())
				{
					LastAlexOwner = Alex->getPlayer();
				}
				if(Aswan && Aswan->GetBought())
				{
					LastAswanOwner = Aswan->getPlayer();
				}
				if(Luxor && Luxor->GetBought())
				{
					LastLuxorOwner = Luxor->getPlayer();
				}
				if(Hurghada && Hurghada->GetBought())
				{
					LastHurghadaOwner = Hurghada->getPlayer();
				}
				times++;
				pGrid->GetOutput()->PrintMessage("Player : " +to_string(this->GetPlayernum())+ " Now Has Benefit Of All Bought Cities For " +to_string(maxcount)+ " Upcoming MOVING Turns. (Click to continue....) ");
				pGrid->GetInput()->GetPointClicked(a,b);
				pGrid->GetOutput()->ClearStatusBar();

			}
			if(times == 1)
			{
				if(Cairo && Cairo->GetBought())
				{
					Cairo->SetCityOwner(this);
				}
				if(Alex && Alex->GetBought())
				{
					Alex->SetCityOwner(this);
				}
				if(Aswan && Aswan->GetBought())
				{
					Aswan->SetCityOwner(this);
				}
				if(Luxor && Luxor->GetBought())
				{
					Luxor->SetCityOwner(this);
				}
				if(Hurghada && Hurghada->GetBought())
				{
					Hurghada->SetCityOwner(this);
				}		
			}
		}
	}
	//===============================================================
	//===============================================================

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true) (done)
	if(pos.GetCellNum() == 99)
	{
		pGrid->SetEndGame(true);
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}