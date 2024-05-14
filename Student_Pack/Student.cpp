#include "Student.h"

Student::Student(std::string _Name, int _Age, std::string _Direction) : Human(_Name, _Age)
{
	SetName(_Name);
	SetAge(_Age);
	Direction = _Direction;
}

std::string Student::GetDirection()
{
	return Direction;
}

bool Student::AvailabilityOfGradesInSubject(std::string subject)
{
	
	if (marks.size() == 0) return false;

	else
	{
		for (int i = 0; i < marks.size(); i++)
		{
			if (marks[i].GetName() == subject && marks[i].AvailabilityOfAssesment()) return true;
		}
	}

	return false;

}

void Student::AddMark(std::string subject, int Assesment)
{
	for (int i = 0; i < (int)marks.size(); i++)
	{
		if (marks[i].GetName() == subject)
		{
			marks[i].AddAssesment(Assesment);
			return;
		}
	}

	Subject sub(subject);
	sub.AddAssesment(Assesment);
	marks.push_back(sub);
	return;

}

double Student::GetAverageGrade()
{
	int count = marks.size();

	if (count == 0) return true;

	double sum = 0;

	for (int i = 0; i < count; i++)
	{
		sum += marks[i].AverageSummary();
	}

	double result = sum / count;

	return result;
}

bool Student::IsExcellentStudent()
{

	if (GetAverageGrade() >= 4.5) return true;
	else return false;

}

void Student::PrintMarks()
{
	for (int i = 0; i < (int)marks.size(); i++)
	{
		marks[i].PrintMarks();
	}
}
