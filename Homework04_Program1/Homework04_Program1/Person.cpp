#include "Person.h"

Person::Person()
{

}
//Overloaded constructor creates a person using all given information
Person::Person(string n, int d, int w, int i)
{
	name = n;
	depId = d;
	wage = w;
	id = i;
}

void Person::setName(string n)
{
	name = n;
}
void Person::setDepId(int d)
{
	depId = d;
}
void Person::setWage(double w)
{
	wage = w;
}
void Person::setId(int i)
{
	id = i;
}

string Person::getName() const
{
	return name;
}
int Person::getDepId() const
{
	return depId;
}
double Person::getWage() const
{
	return wage;
}
int Person::getId() const
{
	return id;
}