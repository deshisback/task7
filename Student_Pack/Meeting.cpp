#include "Meeting.h"

void Meeting::AddTeacherToMeeting(Teacher* teacher)
{

	if (std::find(Teachers.begin(), Teachers.end(), teacher) != Teachers.end())
	{
		return;
	}

	Teachers.push_back(teacher);

}

void Meeting::AddParentToMeeting(Parent* parent)
{

	if (std::find(Parents.begin(), Parents.end(), parent) != Parents.end())
	{
		return;
	}

	Parents.push_back(parent);

}

void Meeting::AddGrandMotherToMeeting(Grandmother* grandmother)
{
	if (std::find(GrandMothers.begin(), GrandMothers.end(), grandmother) != GrandMothers.end())
	{
		return;
	}

	GrandMothers.push_back(grandmother);
}

void Meeting::ParentTellAboutChild()
{

	for (int i = 0; i < Teachers.size(); i++)
	{
		for (int j = 0; j < Parents.size(); j++)
		{
			std::string subject = Teachers[i]->GetTeacherSubject();
			Parents[j]->TellAboutChildrenInTheSubject(subject);
		}
	}

	for (int i = 0; i < Teachers.size(); i++)
	{
		for (int j = 0; j < GrandMothers.size(); j++)
		{
			std::string subject = Teachers[i]->GetTeacherSubject();
			GrandMothers[j]->TellAboutChildrenInTheSubject(subject);
		}
	}

}

void Meeting::ListOfChildrenOfAbsentParent(ParentPseudoInterface ppi)
{

	for (int i = 0; i < ppi.CountOfParents(); i++)
	{
		if (!(std::find(Parents.begin(), Parents.end(), ppi.ReturnParentFromAllParents(i)) != Parents.end()))
			ppi.PrintChildrenOfParent(ppi.ReturnParentFromAllParents(i));
	}

}