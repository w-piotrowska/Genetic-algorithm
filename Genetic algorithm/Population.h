#pragma once
#include "Person.h"
class Population
{
public:
	Population();
	Population(int p_size, int g, int num);	//pusta populacja
	Population(int p_size, int num);	//losowa populacja
	~Population();
	int computeGrade(int** flows, int** distance);
	Person & tournament(int tour);
	Person & crossover(Person & pcOther);
	Person & mutation(Person & pcOther);
	Person* randomPerson();
	void addPerson(Person & per);
	int getActualSize();
	void setActualSize(int i);


private:
	Person * people;
	int pop_size;    
	int actual_size;
	int number_of_generation;
	int n;
};

