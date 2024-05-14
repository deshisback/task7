#pragma once
#include "Student.h"
#include "Mood.h"
#include <ctime>

class Teacher : public Human
{
	
private:

	Mood TeacherMood;
	std::string CurrentState;
	std::string TeacherSubject;
	int TimeToSwitchMood = 5;

public:

	Teacher(std::string _Name, int _Age) : Human(_Name, _Age) {};

	void SetTeacherSubject(std::string subject);

	std::string GetTeacherSubject();

	void SetTimeToSwitchMood(int Time);

	void AddMarkToStudent(Student*& student, std::string subject, int assesment);

	void SetMood(std::string _mood);

	void AddMoodToTeacher(std::string _mood);

	void SetState(std::string _state);

};

