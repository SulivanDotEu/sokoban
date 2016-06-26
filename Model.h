#pragma once

#include "Game.h"
#include <string>

#define LEFT 10
#define RIGHT 20
#define UP 30
#define DOWN 40

class Model
{
public:
	Model(void);
	~Model(void);
	static Model *getInstance();
	void move(int);
	void newGame(std::string);
	Case getCase(int,int);

private:
	static Model *instance;	
	Game * game;
};

