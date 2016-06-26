#include "CaseContents.h"
#include "Model.h"


CaseContents::CaseContents(void)
{
}


CaseContents::~CaseContents(void)
{
}

void CaseContents::setCoord(int x, int y)
{
	this->x = x;
	this->y = y;
}
bool CaseContents::move(int dir)
{
	switch (dir) {
	case LEFT: {
		return Model::getInstance()->getCase(x, y-1).move(dir); }

	case RIGHT:{return Model::getInstance()->getCase(x, y+1).move(dir); }
	case UP:{return Model::getInstance()->getCase(x-1, y).move(dir); }
	case DOWN:{return Model::getInstance()->getCase(x+1, y).move(dir); }
	}
	return true;
}
