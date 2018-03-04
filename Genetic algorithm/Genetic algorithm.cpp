// Genetic algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"
#include "Evolution.h"
#include <iostream>

using namespace std;

int main()
{
	double pm = 0.01;
	double px = 0.7;
	int pop_size = 6;
	int gen = 2;
	int tour = 5;
	int n = 4;
	int**flows = new int*[n];
	for (int i = 0; i < n; i++)
	{
		flows[i] = new int[n];
	}
	int** distance = new int*[n];
	for (int i = 0; i < n; i++)
	{
		distance[i] = new int[n];
	}
	flows[0][0] = 0;
	flows[0][1] = 3;
	flows[0][2] = 0;
	flows[0][3] = 2;
	flows[1][0] = 3;
	flows[1][1] = 0;
	flows[1][2] = 0;
	flows[1][3] = 1;
	flows[2][0] = 0;
	flows[2][1] = 0;
	flows[2][2] = 0;
	flows[2][3] = 4;
	flows[3][0] = 2;
	flows[3][1] = 1;
	flows[3][2] = 4;
	flows[3][3] = 0;

	distance[0][0] = 0;
	distance[0][1] = 22;
	distance[0][2] = 53;
	distance[0][3] = 53;
	distance[1][0] = 22;
	distance[1][1] = 0;
	distance[1][2] = 40;
	distance[1][3] = 62;
	distance[2][0] = 53;
	distance[2][1] = 40;
	distance[2][2] = 0;
	distance[2][3] = 55;
	distance[3][0] = 53;
	distance[3][1] = 62;
	distance[3][2] = 55;
	distance[3][3] = 0;
	/*Evolution e(pm, px, pop_size, gen, tour, n, flows, distance);
	int res;
	res = e.run();
	cout << res << endl;*/
	srand(time(NULL));
	/*Population p(10, 4);
	p.randomPopulation();
	cout << p.toString() << endl << endl;
	int res = p.computeGrade(flows, distance);

	cout << p.toString() << endl << endl;
	cout << res << endl << endl;

	Person per = p.tournament(1);
	Person per2 = p.tournament(1);
	cout << per.toString() << endl << endl;
	cout << per2
		.toString() << endl << endl;

	Person per3 = p.mutation(per);
	cout << per3.toString() << endl << endl;*/

	Evolution e(pm, px, pop_size, gen, tour, n, flows, distance);
	e.run();
	Population pop(4, 4);
	pop.randomPopulation();
	int res;
	res = pop.computeGrade(flows, distance);

	system("PAUSE");
    return 0;
}

