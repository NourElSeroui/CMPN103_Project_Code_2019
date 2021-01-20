#pragma once
#include "card.h"

class Card15 :
	public Card
{
	bool IsApplied;
public:
	Card15(CellPosition & pos);
	Player * pOwner;
	Input * pIn;
	Output * pOut;
	int InputTurns;
	virtual void ReadCardParameters(Grid * pGrid);
	virtual void Apply(Grid * pGrid,Player * pPlayer);
	void setInputTurns(int it);
	int getInputTurns() const;
	virtual void Save(ofstream &,int type);
	virtual void Load(ifstream &,int type);
	~Card15();
};

