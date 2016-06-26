#pragma once

#include "CaseContents.h"

class Case
{
public:
	Case(void);
	Case(int x, int y, CaseContents *contents);
	~Case(void);
	CaseContents *getContents();
	void setContents(CaseContents *);
	int getX();
	int getY();
	void init(int x, int y, CaseContents *contents);
	bool move(int);

protected:
	CaseContents *contents;
	int x;
	int y;
};