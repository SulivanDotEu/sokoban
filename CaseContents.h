#pragma once

class CaseContents
{
public:
	CaseContents(void);
	~CaseContents(void);
	int getX(){return x;};
	int getY(){return y;};
	void setCoord(int,int);
	virtual bool move(int);


protected:
	int x;
	int y;
};
