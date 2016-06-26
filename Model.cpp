#include "Model.h"

Model *Model::instance = 0;

Model::Model(void)
{
}


Model::~Model(void)
{
}

Model *Model::getInstance(){
	if (instance == 0)
		instance = new Model();

	return instance;
}

void Model::newGame(std::string name)
{
	game = new Game(name);
}

Case Model::getCase(int x, int y)
{
	return game->getCase(x,y);
}

void Model::move(int dir){

	if (game->getPlayer()->move(dir)){
		//vue;
	}

}