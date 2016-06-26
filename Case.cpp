#include "Case.h"


Case::Case(void)
{
}

Case::Case(int x, int y, CaseContents *contents)
{
	this->x = x;
	this->y = y;
	this->contents = contents;
	this->contents->setCoord(x, y);
}

Case::~Case(void)
{
}

CaseContents *Case::getContents()
{
	return contents;
}

void Case::setContents(CaseContents *contents)
{
	this->contents = contents;
	this->contents->setCoord(x, y);
}

int Case::getX()
{
	return x;
}

int Case::getY()
{
	return y;
}

void Case::init(int x, int y, CaseContents *contents)
{
	this->x = x;
	this->y = y;
	this->contents = contents;
	this->contents->setCoord(x, y);
}

bool Case::move(int dir)
{
	if (contents == 0) {return true;}
	else {return contents->move(dir);}
}