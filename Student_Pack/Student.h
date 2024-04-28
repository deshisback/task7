#pragma once
#include "Human.h"
#include "Subject.h"

class Student : public Human
{

private:

	std::string Direction;
	std::vector<Subject> marks;

public:

	Student(std::string _Name, int _Age, std::string _Direction);

	std::string GetDirection();

	void AddMark(std::string subject, int Assesment);

	bool IsExcellentStudent();

	void PrintMarks();

};

