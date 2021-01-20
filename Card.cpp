#include "Card.h"

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{}
Card::~Card()
{}
void Card::SetCardNumber(int cnum)
{
	if (cnum>=1 && cnum<=15)
		cardNumber = cnum; // needs validation
}
int Card::GetCardNumber()
{
	return cardNumber;
}
void Card::Draw(Output* pOut) const
{
	//TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position,cardNumber);
}
void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}
void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// The following line is to print the following message if a player reaches a card of any type
	int x,y;
	Input *PIn=pGrid->GetInput();
	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
	PIn->GetPointClicked(x,y);
}
