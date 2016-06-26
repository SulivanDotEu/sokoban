#pragma once
#include "casecontents.h"
class Receiver :
	public CaseContents
{
public:
	Receiver(void);
	~Receiver(void);
	virtual bool move(int dir){
		return false;
	};
};

