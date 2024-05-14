#pragma once
#include "Teacher.h"
#include "ParentPseudoInterface.h"

class Meeting
{

private:

	std::vector<Teacher*> Teachers;
	std::vector<Parent*> Parents;

public:

	void AddTeacherToMeeting(Teacher* teacher);

	void AddParentToMeeting(Parent* parent);

	void ParentTellAboutChild();

	void ListOfChildrenOfAbsentParent(ParentPseudoInterface ppi);

};

