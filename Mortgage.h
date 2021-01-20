#pragma once
#include "OfferMortgageAction.h"

class Mortgage
{
int whichCard;
int lastOwnerNum;
public:
	Mortgage();
	Mortgage(int w,int l);
	void setWhichCard(int w);
	void setLastOwnerNum(int l);
	int getWhichCard() const;
	int getLastOwnerNum() const;
	~Mortgage();
};