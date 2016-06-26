#pragma once

#include <string>
#include "Player.h"
#include "Case.h"
#include <vector>

using namespace std;
class Game
{
public:
	Game(void);
	Game(std::string);
	~Game(void);
	bool isHeAWinner();
	Case getCase(int,int);
	Player* getPlayer();

private:
	string name;
	vector<vector<Case>> map;
	Player *player;
	bool win;
	void loadMap();
};

