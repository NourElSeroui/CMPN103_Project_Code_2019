#pragma once
#include"Card.h"


class Card2: public Card
{
public:
	Card2(const CellPosition & pos);

	virtual void Save(ofstream &,int type);

	virtual void Load(ifstream &,int type);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual ~Card2(void);
};

