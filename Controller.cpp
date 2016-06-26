#include "Controller.h"

Controller *Controller::instance=0;

Controller::Controller(void)
{
}


Controller::~Controller(void)
{
}

Controller *Controller::getInstance()
{
	if (instance == 0)
		instance = new Controller();
	return instance;
}
