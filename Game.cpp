#include "Game.h"
#include "Wall.h"
#include "Box.h"
#include "Receiver.h"
Game::Game(void)
{

}

Game::Game(string name)
{
	this->name = name;
	this->player = new Player;
	this->win = false;
}


Game::~Game(void)
{
}

Case Game::getCase(int x, int y)
{
	return map[x][y];
}

Player *Game::getPlayer()
{
	return player;
}

bool Game::isHeAWinner()
{
	return win;
}

void Game::loadMap()
{
	vector< vector<Case> > t(6, vector<Case>(6)); 
	map = t;

	map[0][0].init(0,0, new Wall());
	map[0][1].init(0,1, new Wall());
	map[0][2].init(0,2, new Wall());
	map[0][3].init(0,3, new Wall());
	map[0][4].init(0,4, new Wall());
	map[0][5].init(0,5, new Wall());

	map[1][0].init(1,0, new Wall());
	map[1][1].init(1,1, 0);
	map[1][2].init(1,2, 0);
	map[1][3].init(1,3, 0);
	map[1][4].init(1,4, 0);
	map[1][5].init(1,5, new Wall());

	map[2][0].init(2,0, new Wall());
	map[2][1].init(2,1, 0);
	map[2][2].init(2,2, player);
	map[2][3].init(2,3, new Box());
	map[2][4].init(2,4, 0);
	map[2][5].init(2,5, new Wall());

	map[3][0].init(3,0, new Wall());
	map[3][1].init(3,1, 0);
	map[3][2].init(3,2, new Box());
	map[3][3].init(3,3, 0);
	map[3][4].init(3,4, new Receiver());
	map[3][5].init(3,5, new Wall());

	map[4][0].init(4,0, new Wall());
	map[4][1].init(4,1, new Receiver());
	map[4][2].init(4,2, 0);
	map[4][3].init(4,3, 0);
	map[4][4].init(4,4, 0);
	map[4][5].init(4,5, new Wall());

	map[5][0].init(5,0, new Wall());
	map[5][1].init(5,1, new Wall());
	map[5][2].init(5,2, new Wall());
	map[5][3].init(5,3, new Wall());
	map[5][4].init(5,4, new Wall());
	map[5][5].init(5,5, new Wall());
}