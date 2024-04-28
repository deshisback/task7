#include "Human.h"

int Human::GetAge()
{
	return Age;
}

std::string Human::GetName()
{
	return Name;
}

Human::Human(std::string _Name, int _Age)
{
	Name = _Name;
	Age = _Age;
}

void Human::SetAge(int _Age)
{
	Age = _Age;
}

void Human::SetName(std::string _Name)
{
	Name = _Name;
}