#include "stdafx.h"
#include "Evolution.h"


Evolution::Evolution()
{
}

Evolution::Evolution(double prm, double prx, int p_size, int generations, int t, int n_of_gens, int ** fl, int ** dis)
{
	pm = prm;
	px = prx;
	pop_size = p_size;
	gen = generations;
	tour = t;
	n = n_of_gens;
	flows = new int*[n];
	for (int i = 0; i < n; i++)
	{
		flows[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			flows[i][j] = fl[i][j];
		}
	}
	distance = new int*[n];
	for (int i = 0; i < n; i++)
	{
		distance[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			distance[i][j] = dis[i][j];
		}
	}
	populations = new Population[gen];
}


Evolution::~Evolution()
{
	delete populations;
	for (int i = 0; i < n; i++)
	{
		delete flows[i];
	}
	for (int i = 0; i < n; i++)
	{
		delete distance[i];
	}
	delete flows;
	delete distance;
}

int Evolution::run()
{
	int result;
	Population actual_pop = createRandomPopulation();
	result = actual_pop.computeGrade(flows, distance);
	Population pop(pop_size, 2, n);
	for (int i = 1; i < gen; i++)
	{
		Person p;
		while (pop.getActualSize() <= pop_size)
		{
			p = selection(actual_pop);
			srand(time(NULL));
			double prawd = (double)rand() / (double)RAND_MAX;
			if (prawd < px)
			{
				p = crossover(actual_pop, p);
			}
			srand(time(NULL));
			prawd = (double)rand() / (double)RAND_MAX;
			if (prawd > pm)
			{
				p = mutation(actual_pop, p);
			}
			pop.addPerson(p);
		}
		result = pop.computeGrade(flows, distance);
		actual_pop = pop;
		pop.setActualSize(0);
	}    
	return result;

}

Population Evolution::createRandomPopulation()
{
	Population *p = new Population(pop_size, tour, n);
	return *p;
}

int Evolution::computeGrade(Population pop)
{
	return pop.computeGrade(flows, distance);
}

Person & Evolution::selection(Population pop)
{
	return pop.tournament(tour);
}

Person & Evolution::crossover(Population pop, Person per)
{
	return pop.crossover(per);
}

Person & Evolution::mutation(Population pop, Person per)
{
	return pop.mutation(per);
}
