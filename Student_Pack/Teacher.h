#pragma once
#include "Student.h"
#include <ctime>

class Teacher : public Human
{
	
private:

	std::string CurrentMood;
	std::string CurrentState;

public:

	Teacher(std::string _Name, int _Age) : Human(_Name, _Age) {};

	void AddMarkToStudent(Student*& student, std::string subject, int assesment);

	void SetMood(std::string _mood);

	void SetState(std::string _state);

};

