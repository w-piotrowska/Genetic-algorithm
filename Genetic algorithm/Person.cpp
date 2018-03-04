#include "stdafx.h"
#include "Person.h"


Person::Person()
{
	/*n = 5;
	genes = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		genes[i] = 1 + rand() % (n-1);
	}*/
}

Person::Person(int number)
{
	n = number;
	genes = new int[n];
	for (int i = 0; i < n; i++)
	{
		genes[i] = 1 + rand() % (n - 1);
	}
	fix();
}

Person::Person(int number, int* g)
{
	n = number;
	genes = new int[n];
	for (int i = 0; i < n; i++)
	{
		genes[i] = g[i];
	}
}

Person::Person(const Person & pcOther)
{
	n = pcOther.n;
	genes = new int[n];
	for (int i = 0; i < n; i++)
	{
		genes[i] = pcOther.genes[i];
	}
	grade = pcOther.grade;
}

Person::~Person()
{
	//delete genes;
}

Person & Person::operator=(Person & pcOther)
{
	n = pcOther.n;
	//delete genes;
	genes = new int[n];
	for (int i = 0; i < n; i++)
	{
		genes[i] = pcOther.genes[i];
	}
	grade = pcOther.grade;
	return *this;
}

string Person::toString()
{
	string result = "";
	for (int i = 0; i < n; i++)
	{
		result += to_string(genes[i]) + " ";
	}
	result += to_string(grade);
	return result;
}

int Person::evaluating_result(int ** flows, int ** distance)
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res += flows[genes[i]-1][genes[j]-1] * distance[i][j];
		}
	}
	grade = res;
	return res;
}

void Person::swap()
{
	int ran1 = rand() % n;
	int tmp = genes[ran1];
	int ran2 = rand() % n;
	genes[ran1] = genes[ran2];
	genes[ran2] = tmp;
}

void Person::fix()
{
	int* tab = new int[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		tab[genes[i]-1] ++;
	}

	for (int i = 0; i < n; i++)
	{
		if (tab[genes[i]-1] > 1)
		{
			tab[genes[i] - 1]--;
			int j = 0;
			while (tab[j] != 0)
			{
				j++;
			}
			genes[i] = j + 1;
			tab[j]++;
		}
	}
	
}

Person & Person::crossover(Person & pcOther)
{
	int cut = rand() % n;
	int* g = new int[n];
	for (int i = 0; i <= cut; i++)
	{
		g[i] = genes[i];
	}
	for (int i = cut+1; i < n; i++)
	{
		g[i] = pcOther.genes[i];
	}
	Person *child = new Person(n, g);
	child->fix();
	//delete g;
	return *child;
}

int * Person::getGenes()
{
	return genes;
}

int Person::getGrade()
{
	return grade;
}



