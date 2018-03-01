#pragma once
#include "Population.h"
class Evolution
{
public:
	Evolution();
	Evolution(double prm, double prx, int p_size, int generations, int t, int n_of_gens, int ** fl, int ** dis);
	~Evolution();
	int run();
	Population createRandomPopulation();
	int computeGrade(Population pop);
	Person & selection(Population pop);
	Person & crossover(Population pop, Person per);
	Person & mutation(Population pop, Person per);

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

