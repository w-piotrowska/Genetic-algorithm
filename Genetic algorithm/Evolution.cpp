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
	flows = fl;
	/*for (int i = 0; i < n; i++)
	{
		flows[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			flows[i][j] = fl[i][j];
		}
	}*/
	distance = new int*[n];
	distance = dis;
	//for (int i = 0; i < n; i++)
	//{
	//	distance[i] = new int[n];
	//	for (int j = 0; j < n; j++)
	//	{
	//		distance[i][j] = dis[i][j];
	//	}
	//}
	//populations = new Population[gen];
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
	Population actual_pop(pop_size, n);
	actual_pop.randomPopulation();
	result = actual_pop.computeGrade(flows, distance);
	Population pop(pop_size, n);
	for (int i = 1; i < gen; i++)
	{
		for (int j = 0; j < pop_size; j++)
		{
			Person p1 = selection(actual_pop);
			Person p2 = selection(actual_pop);
			/*double prawd = (double)rand() / (double)RAND_MAX;
			if (prawd < px)
			{
				p = crossover(actual_pop, p);
			}
			prawd = (double)rand() / (double)RAND_MAX;
			if (prawd > pm)
			{
				p = crossover(actual_pop, p);
			}*/
			Person p3 = crossover(actual_pop, p1, p2);
			Person p = mutation(actual_pop, p3);
			pop.addPerson(p);
		}
		result = pop.computeGrade(flows, distance);
		actual_pop = pop;
		pop.clear();
	}    
	return result;

}

Population Evolution::createRandomPopulation()
{
	Population *p = new Population(pop_size, n);
	return *p;
}

int Evolution::computeGrade(Population pop)
{
	return pop.computeGrade(flows, distance);
}

Person Evolution::selection(Population pop)
{
	return pop.tournament(tour);
}

Person Evolution::crossover(Population pop, Person per1, Person per2)
{
	return pop.crossover(per1, per2);
}

Person Evolution::mutation(Population pop, Person per)
{
	return pop.mutation(per);
}
