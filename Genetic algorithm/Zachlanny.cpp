#include "stdafx.h"
#include "Zachlanny.h"


Zachlanny::Zachlanny(string f_name)
{
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


Zachlanny::~Zachlanny()
{
}

void Zachlanny::run()
{
	for (int k = 0; k < 20; k++)
	{
		int * genes = new int[n];
		genes[0] = rand() % n + 1;
		vector<bool> vec;
		for (int i = 0; i < n; i++)
		{
			vec.push_back(true);
		}
		vec[genes[0]-1] = false;
		for (int i = 1; i < n; i++)
		{
			int dist = 0;
			int min = INT32_MAX;
			for (int j = 0; j < n; j++)
			{
				if (vec[j])
				{
					dist = flows[genes[i-1]-1][j] * distance[i][j];
					if (min > dist)
					{
						if(min != INT32_MAX)
							vec[genes[i]-1] = true;
						min = dist;
						genes[i] = j + 1;
						vec[genes[i]-1] = false;
					}
				}
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			cout << genes[i] << "\t";
		}
	}
}
