#include "Teacher.h"

int TimeToSwitchMood = 5;

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

	else if (IsEscellent && TeacherMood.GetCurrentMood() == "good" && assesment == 5)
	{
		student->AddMark(subject, assesment);
	}

	else if (IsEscellent && TeacherMood.GetCurrentMood() == "bad" && assesment == 5)
	{
		student->AddMark(subject, 4 + (rand() % 2));
	}

	else if (!IsEscellent && TeacherMood.GetCurrentMood() == "good" && assesment == 5)
	{
		student->AddMark(subject, 4);
	}

	else if (!IsEscellent && TeacherMood.GetCurrentMood() == "bad" && assesment == 5)
	{
		student->AddMark(subject, 2 + (rand() % 2));
	}

	else student->AddMark(subject, assesment);

	
	TimeToSwitchMood--;

	if (TimeToSwitchMood == 0)
	{
		TeacherMood.RandomUpdateMood();
		TimeToSwitchMood = 5;
	}
}

void Teacher::SetMood(std::string _mood)
{
	TeacherMood.SetMood(_mood);
}

void Teacher::AddMoodToTeacher(std::string _mood)
{
	TeacherMood.AddMood(_mood);
}

void Teacher::SetState(std::string _state)
{

	if (_state == "bozhenka") CurrentState = "bozhenka";

	else if (_state == "gnida") CurrentState = "gnida";

	else CurrentState = "normis";

}
