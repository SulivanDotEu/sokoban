#include "View.h"

View *View::instance=0;

View::View(void)
{
}


View::~View(void)
{
}

View *View::getInstance()
{
	if (View::instance == 0 )
		instance = new View();

	return instance;
}
