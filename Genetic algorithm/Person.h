#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
using namespace std;
class Person
{
public:
	Person();
	Person(int number);
	Person(int number, int* g);
	Person(const Person &pcOther);
	~Person();
	Person& operator=(Person &pcOther);
	string toString();
	int evaluating_result(int** flows, int** distance);
	void swap();
	void mutation(double pm);
	void fix();
	Person& crossover(Person &pcOther);
	int* getGenes();
	int getGrade();

private:
	int n;
	int *genes;
	int grade;
	int** flows;
	int**distance;
};

