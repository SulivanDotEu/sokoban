#pragma once
#include "Model.h"

class View
{
public:
	View(void);
	~View(void);
	static View *getInstance();
private:

	static View *instance;		// Instance de la vue pour le pattern singleton
	//Model *model;
};

