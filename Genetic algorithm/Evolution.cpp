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
	int result = 0;
	Population actual_pop(pop_size, n);
	actual_pop.randomPopulation();
	actual_pop.computeGrade(flows, distance);

	ofstream plik;
	plik.open("ga.txt");
	plik << n << "\t";
	plik << actual_pop.minGrade() << "\t";
	plik << actual_pop.maxGrade() << "\t";
	plik << actual_pop.averageGrade();
	plik << endl;

	Population pop(pop_size, n);
	for (int i = 1; i < gen; i++)
	{
		for (int j = 0; j < pop_size / 2; j++)
		{
			Person p1 = selection(actual_pop);
			Person p2 = selection(actual_pop);
			double prawd = (double)rand() / (double)RAND_MAX;
			if (prawd < px)
			{
				Person p3 = crossover(actual_pop, p1, p2);
				Person p4 = crossover(actual_pop, p2, p1);
				prawd = (double)rand() / (double)RAND_MAX;
				if (prawd > pm)
				{
					Person p = mutation(actual_pop, p3);
					pop.addPerson(p);
				}
				else
				{
					pop.addPerson(p3);
				}
				prawd = (double)rand() / (double)RAND_MAX;
				if (prawd > pm)
				{
					Person p = mutation(actual_pop, p4);
					pop.addPerson(p);
				}
				else
				{
					pop.addPerson(p4);
				}
			}
			else
			{
				if (prawd > pm)
				{
					Person p = mutation(actual_pop, p1);
					pop.addPerson(p);
				}
				else
				{
					pop.addPerson(p1);
				}
				prawd = (double)rand() / (double)RAND_MAX;
				if (prawd > pm)
				{
					Person p = mutation(actual_pop, p2);
					pop.addPerson(p);
				}
				else
				{
					pop.addPerson(p2);
				}
			}
		}
		pop.computeGrade(flows, distance);
		plik << n << "\t";
		plik << pop.minGrade() << "\t";
		plik << pop.maxGrade() << "\t";
		plik << pop.averageGrade();
		plik << endl;


		actual_pop = pop;
		pop.clear();
	}    
	plik.close();
	return result;

}

Population Evolution::createRandomPopulation()
{
	Population *p = new Population(pop_size, n);
	return *p;
}

void Evolution::computeGrade(Population pop)
{
	pop.computeGrade(flows, distance);
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
