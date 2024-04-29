#include "Teacher.h"

void Teacher::AddMarkToStudent(Student*& student, std::string subject, int assesment)
{
	bool IsEscellent = student->IsExcellentStudent();

	if (CurrentState == "bozhenka")
	{
		student->AddMark(subject, 5);
	}

	else if (CurrentState == "gnida")
	{
		student->AddMark(subject, 2);
	}

	else if (IsEscellent && CurrentMood == "good" && assesment == 5)
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

void Teacher::SetState(std::string _state)
{

	if (_state == "bozhenka") CurrentState = "bozhenka";

	else if (_state == "gnida") CurrentState = "gnida";

	else CurrentState = "normis";

}
