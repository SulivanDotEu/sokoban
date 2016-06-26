#pragma once
#include "casecontents.h"
class Wall :
	public CaseContents
{
public:
	Wall(void);
	~Wall(void);
	
	virtual bool move(int dir){
		return false;
	};
};

