#pragma once
#include "Population.h"
#include <fstream>
class Zachlanny
{
public:
	Zachlanny(string f_name);
	~Zachlanny();

	void run();

private:
	int n;
	int ** flows;
	int ** distance;
};

