#pragma once
#include <string>
#include "Case.h"

class Level
{
public:
	Level(void);
	~Level(void);

private:
	std::string name;
	Case **map;

};

