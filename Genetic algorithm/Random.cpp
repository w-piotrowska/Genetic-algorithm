#include "stdafx.h"
#include "Random.h"


Random::Random(int p_size, string f_name)
{
	pop_size = p_size;
	ifstream plik;
	plik.open(f_name);
	plik >> n;

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

Random::~Random()
{
}

void Random::run()
{
	ofstream plik;
	string name = to_string(n) + "__random.csv";
	plik.open(name);
	for (int k = 0; k < n; k++)
	{
		Population actual_pop(pop_size, n);
		actual_pop.randomPopulation();
		actual_pop.computeGrade(flows, distance);
		plik << actual_pop.minGrade() << endl;
	}
}
