#include "Mortgage.h"

Mortgage::Mortgage()
{
	whichCard=-1;
	lastOwnerNum=-1;
}


Mortgage::Mortgage(int w,int l)
{
	setWhichCard(w);
	setLastOwnerNum(l);
}

void Mortgage::setLastOwnerNum(int l)
{
	lastOwnerNum = l;
}


int Mortgage::getLastOwnerNum() const
{
	return lastOwnerNum;
}

void Mortgage::setWhichCard(int w)
{
	whichCard = w;
}


int Mortgage::getWhichCard() const
{
	return whichCard;
}




Mortgage::~Mortgage()
{
}
