#pragma once
#include "Human.h"
#include "Student.h"
#include "Mood.h"

class Grandmother : public Human
{

private:

	Mood GrandmotherMood;
	std::vector<Student*> GrandChildren;

public:

	void Telling(Student* student);

	Grandmother(std::string _Name, int _Age) : Human(_Name, _Age) {};

	void AddGrandChildren(Student* child);

	void TellAboutAllChildren();

	void TellAboutRandomChild();

	void TellSummaryAboutChildren();

	void TellAboutChildrenInTheSubject(std::string subject);

	void AddMoods(std::string _mood);

	void SetCurrentMood(std::string _mood);

	void TellChildrenNames();

	std::string GetCurrentMood();

};

