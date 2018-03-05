#include "stdafx.h"
#include "Population.h"


Population::Population()
{
}

Population::Population(int p_size, int num)
{
	pop_size = p_size;
	n = num;
	actual_size = 0;
	people.reserve(pop_size);
}

Population::~Population()
{
	//delete people;
}

//Population & Population::operator=(Population & pcOther)
//{
//	// TODO: tu wstawiæ instrukcjê return
//}

void Population::computeGrade(int** flows, int** distance)
{
	for (int i = 0; i < pop_size; i++)
	{
		people[i].evaluating_result(flows, distance);
	}
}

Person  Population::tournament(int tour)
{
	vector<Person> zaw(tour);
	zaw[0] = *randomPerson();
	int the_best = 0;
	for (int i = 1; i < tour; i++)
	{
		zaw[i] = *randomPerson();
		if (zaw[i].getGrade() < zaw[the_best].getGrade())
		{
			the_best = i;
		}
	}
	Person p = zaw[the_best];
	return p;
}

Person Population::crossover(Person pcOther1, Person pcOther2)
{
	return pcOther1.crossover(pcOther2);
}

Person Population::mutation(Person pcOther)
{
	pcOther.swap();
	return pcOther;
}

Person* Population::randomPerson()
{
	return &(people[rand() % pop_size]);
}

void Population::addPerson(Person & per)
{
	people.push_back(per);
	actual_size++;
}

void Population::addRandomPerson()
{
	people.push_back(Person(n));
	actual_size++;
}

void Population::randomPopulation()
{
	for (int i = 0; i < pop_size; i++)
	{
		addRandomPerson();
	}
}

int Population::getActualSize()
{
	return actual_size;
}

void Population::setActualSize(int i)
{
	actual_size = i;
}

string Population::getPerson(int i)
{
	return people[i].toString();
}

string Population::toString()
{
	string res = "";
	for (int i = 0; i < actual_size; i++)
	{
		res += getPerson(i) + "\n";
	}
	return res;
}

void Population::clear()
{
	actual_size = 0;
	people.clear();
}

int Population::maxGrade()
{
	int max = 0;
	for (int i = 0; i < actual_size; i++)
	{
		if (max < people[i].getGrade())
		{
			max = people[i].getGrade();
		}
	}
	return max;
}

int Population::minGrade()
{
	int min = people[0].getGrade();
	for (int i = 0; i < actual_size; i++)
	{
		if (min > people[i].getGrade())
		{
			min = people[i].getGrade();
		}
	}
	return min;
}

double Population::averageGrade()
{
	double avr = 0;
	for (int i = 0; i < actual_size; i++)
	{
		avr += (double)people[i].getGrade() / (double)actual_size;
	}
	return avr;
}
