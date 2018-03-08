// Genetic algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"
#include "Evolution.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	double pm = 0.5;
	double px = 0.7;
	int pop_size = 100;
	int gen = 600;
	int tour = 5;

	srand(time(NULL));
	

	Evolution e(pm, px, pop_size, gen, tour, "had18.dat");
	e.run();

	system("PAUSE");
    return 0;
}

