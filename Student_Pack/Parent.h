#pragma once
#include "Human.h"
#include "Student.h"
#include "Mood.h"

class Parent : public Human 
{

private:

	Mood ParentMood;
	std::vector<Student*> Children;

	void Tellling(int i);

public:

	Parent(std::string _Name, int _Age) : Human(_Name, _Age) {};

	void AddChildren(Student* child);

	void TellAboutAllChildren();

	void TellAboutRandomChild();

	void TellSummaryAboutChildren();
	
	void TellAboutSpecificChild(Student* student);

	void TellAboutChildrenInTheSubject(std::string subject);

	void AddMoods(std::string _mood);

	void SetCurrentMood(std::string _mood);

	void TellChildrenNames();

	std::string GetCurrentMood();

	Student* GetChild(int i); // надобность под вопросом

};


