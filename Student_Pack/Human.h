#pragma once
#include <iostream>

class Human
{
private:

	std::string Name;
	unsigned int Age;

public:

	int GetAge();

	std::string GetName();

	void SetAge(int _Age);

	void SetName(std::string _Name);

	Human(std::string _Name, int _Age);

};

