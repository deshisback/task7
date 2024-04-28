#include "Teacher.h"

void Teacher::AddMarkToStudent(Student*& student, std::string subject, int assesment)
{
	bool IsEscellent = student->IsExcellentStudent();

	if (IsEscellent && CurrentMood == "good" && assesment == 5)
	{
		student->AddMark(subject, assesment);
	}

	else if (IsEscellent && CurrentMood == "bad" && assesment == 5)
	{
		student->AddMark(subject, 4 + (rand() % 2));
	}

	else if (!IsEscellent && CurrentMood == "good" && assesment == 5)
	{
		student->AddMark(subject, 4);
	}

	else if (!IsEscellent && CurrentMood == "bad" && assesment == 5)
	{
		student->AddMark(subject, 2 + (rand() % 2));
	}

	else student->AddMark(subject, assesment);
}

void Teacher::SetMood(std::string _mood)
{
	if (_mood == "good") CurrentMood = "good";

	else CurrentMood = "bad";
}
