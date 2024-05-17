#pragma once
#include "Teacher.h"
#include "ParentPseudoInterface.h"

class Meeting
{

private:

	std::vector<Teacher*> Teachers;
	std::vector<Parent*> Parents;
	std::vector<Grandmother*> GrandMothers;

public:

	void AddTeacherToMeeting(Teacher* teacher);

	void AddParentToMeeting(Parent* parent);

	void AddGrandMotherToMeeting(Grandmother* grandmother);

	void ParentTellAboutChild();

	void ListOfChildrenOfAbsentParent(ParentPseudoInterface ppi);

};

