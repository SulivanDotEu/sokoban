#pragma once

#include "Model.h"
#include "View.h"
class Controller
{
public:
	Controller(void);
	~Controller(void);
	static Controller *getInstance();

private:
	static Controller *instance;	// Instance du controlleur pour le pattern singleton
	//Model *model;					// Le M de MVC
	//View  *view;					// Le V de MVC
};

