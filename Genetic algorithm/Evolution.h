#pragma once
#include "Population.h"
#include <fstream>
class Evolution
{
public:
	Evolution();
	Evolution(double prm, double prx, int p_size, int generations, int t, string f_name);
	~Evolution();
	void run(string name);
	Population createRandomPopulation();
	void computeGrade(Population pop);
	Person selection(Population pop);
	Person crossover(Population pop, Person per1, Person per2);
	Person mutation(Population pop, Person per);

	void saveToFile(Population pop, ofstream plik);

private:
	Population * populations;
	double pm;
	double px;
	int pop_size;
	int gen;
	int tour;
	int n;
	int** flows;
	int** distance;
};

