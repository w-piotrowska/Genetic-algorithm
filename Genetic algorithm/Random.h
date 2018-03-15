#pragma once
#include "Population.h"
#include <fstream>
class Random
{
public:
	Random(int p_size, string f_name);
	~Random();
	void run();

private:
	int pop_size;
	int n;
	int ** flows;
	int ** distance;
};

