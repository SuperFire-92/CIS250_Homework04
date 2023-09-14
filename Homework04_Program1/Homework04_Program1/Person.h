#pragma once
#include <iostream>
using namespace std;
class Person
{
private:
	string name;
	int depId;
	double wage;
	int id;
public:
	Person();
	Person(string, int, int, int);

	void setName(string);
	void setDepId(int);
	void setWage(double);
	void setId(int);

	string getName() const;
	int getDepId() const;
	double getWage() const;
	int getId() const;
};

