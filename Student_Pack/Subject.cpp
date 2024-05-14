#include "Subject.h"

Subject::Subject(std::string _SubjectName, std::vector<int> AssesmentArray)
{
	SubjectName = _SubjectName;
	SubjectAssesments.resize(AssesmentArray.size());
	SubjectAssesments = AssesmentArray;
}

Subject::Subject(std::string _SubjectName)
{
	SubjectName = _SubjectName;
}

std::string Subject::GetName()
{
	return SubjectName;
}

void Subject::AddAssesment(int Assesment)
{
	SubjectAssesments.push_back(Assesment);
}

double Subject::AverageSummary()
{
	double summary = 0;
	int count = SubjectAssesments.size() - 1;
	double result = 0;

	for (int i = 0; i <= count; i++)
	{
		summary += SubjectAssesments[i];
	}

	result = summary / count;

	return result;
}

void Subject::PrintMarks()
{
	for (int i = 0; i < (int)SubjectAssesments.size(); i++)
	{
		std::cout << SubjectAssesments[i] << " ";
	}

	std::cout << std::endl;
}

bool Subject::AvailabilityOfAssesment()
{
	if (SubjectAssesments.empty()) return false;
	else return true;
}
