#pragma once
#include "Person.h"
#include <vector>
using namespace std;
class Population
{
public:
	Population();
	Population(int p_size, int num);	
	~Population();
	//Population& operator=(Population &pcOther);
	void computeGrade(int** flows, int** distance);
	Person tournament(int tour);
	Person crossover(Person pcOther1, Person pcOther2);
	Person mutation(Person pcOther);
	Person* randomPerson();
	void addPerson(Person & per);
	void addRandomPerson();
	void randomPopulation();
	int getActualSize();
	void setActualSize(int i);
	string getPerson(int i);
	string toString();

	void clear();

	int maxGrade();
	int minGrade();
	double averageGrade();

private:
	vector<Person> people;
	int pop_size;    
	int actual_size;
	int n;
};

