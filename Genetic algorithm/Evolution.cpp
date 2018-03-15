#include "stdafx.h"
#include "Evolution.h"


Evolution::Evolution()
{
}

Evolution::Evolution(double prm, double prx, int p_size, int generations, int t, string f_name)
{
	ifstream plik;
	plik.open(f_name);
	plik >> n;
	pm = prm;
	px = prx;
	pop_size = p_size;
	gen = generations;
	tour = t;
	flows = new int*[n];
	distance = new int*[n];
	
	for (int i = 0; i < n; i++)
	{
		flows[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		distance[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			plik >> distance[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			plik >> flows[i][j];
		}
	}
	plik.close();
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

void Evolution::run(string name)
{
	string minp = to_string(n) + "_" + name + "_min.csv";
	string maxp = to_string(n) + "_" + name + "_max.csv";
	string avgp = to_string(n) + "_" + name + "_avg.csv";
	ofstream plikmin;
	ofstream plikmax;
	ofstream plikavg;
	plikmin.open(minp);
	plikmax.open(maxp);
	plikavg.open(avgp);

	for (int k = 0; k < 20; k++)
	{
		Population actual_pop(pop_size, n);
		actual_pop.randomPopulation();
		actual_pop.computeGrade(flows, distance);


		//saveToFile(actual_pop, plik);
		//plik << n << "\t";
		plikmin << actual_pop.minGrade() << ";";
		plikmax << actual_pop.maxGrade() << ";";
		plikavg << actual_pop.averageGrade() <<";";

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
					if (prawd < pm)
					{
						Person p = mutation(actual_pop, p3);
						pop.addPerson(p);
					}
					else
					{
						pop.addPerson(p3);
					}
					prawd = (double)rand() / (double)RAND_MAX;
					if (prawd < pm)
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
					prawd = (double)rand() / (double)RAND_MAX;
					if (prawd < pm)
					{
						Person p = mutation(actual_pop, p1);
						pop.addPerson(p);
					}
					else
					{
						pop.addPerson(p1);
					}
					prawd = (double)rand() / (double)RAND_MAX;
					if (prawd < pm)
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
			//plik << n << "\t";
			plikmin << pop.minGrade() << ";";
			plikmax << pop.maxGrade() << ";";
			plikavg << pop.averageGrade() << ";";
			//plik << endl;

			actual_pop = pop;
			pop.clear();
		}
		plikmin << endl;
		plikmax << endl;
		plikavg << endl;
	}
	plikmin.close();
	plikmax.close();
	plikavg.close();

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
	return pop.mutationPerGen(per, pm);
}

void Evolution::saveToFile(Population pop, ofstream plik)
{
	//plik.open("ga.txt");
	plik << n << "\t";
	plik << pop.minGrade() << "\t";
	plik << pop.maxGrade() << "\t";
	plik << pop.averageGrade();
	plik << endl;
}
