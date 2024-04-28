#pragma once
#include <string>
#include <vector>
#include <iostream>

class Subject
{

private:

	std::string SubjectName;
	std::vector<int> SubjectAssesments;

public:

	Subject(std::string _SubjectName, std::vector<int> AssesmentArray);

	Subject(std::string _SubjectName);

	std::string GetName();

	void AddAssesment(int Assesment);

	double AverageSummary();

	void PrintMarks();

};

