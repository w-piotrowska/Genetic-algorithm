#include "stdafx.h"
#include "Population.h"


Population::Population()
{
}

Population::Population(int p_size, int g, int num)
{
	pop_size = p_size;
	number_of_generation = g;
	people = new Person[pop_size];
	actual_size = 0;
	n = num;
}

Population::Population(int p_size, int num)
{
	pop_size = p_size;
	number_of_generation = 1;
	people = new Person[pop_size];
	n = num;
	for (int i = 0; i < pop_size; i++)
	{
		Person p(n);
		people[i] = p;
	}
	actual_size = pop_size;

}

Population::~Population()
{
	//delete people;
}

int Population::computeGrade(int** flows, int** distance)
{
	int min = people[0].evaluating_result(flows, distance);
	for (int i = 1; i < pop_size; i++)
	{
		int tmp = people[i].evaluating_result(flows, distance);
		if (tmp < min)
		{
			min = tmp;
		}
	}
	return min;
}

Person & Population::tournament(int tour)
{
	Person* zaw = new Person[tour];
	Person* res = randomPerson();
	int the_best = res->getGrade();
	for (int i = 1; i < tour; i++)
	{
		zaw[i] = *randomPerson();
		if (zaw[i].getGrade() < the_best)
		{
			*res = zaw[i];
			the_best = zaw[i].getGrade();
		}
	}
	return *res;
}

Person & Population::crossover(Person & pcOther)
{
	Person* parent = randomPerson();
	return pcOther.crossover(*parent);
}

Person & Population::mutation(Person & pcOther)
{
	pcOther.swap();
	return pcOther;
}

Person* Population::randomPerson()
{
	srand(time(NULL));
	return &(people[rand() % pop_size]);
}

void Population::addPerson(Person & per)
{
	people[actual_size] = per;
	actual_size++;
}

int Population::getActualSize()
{
	return actual_size;
}

void Population::setActualSize(int i)
{
	actual_size = i;
}
