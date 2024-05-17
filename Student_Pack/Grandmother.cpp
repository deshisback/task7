#include "Grandmother.h"

void Grandmother::Telling(Student* student)
{

	if (std::find(GrandChildren.begin(), GrandChildren.end(), student) != GrandChildren.end())
	{
		std::cout << "My beautiful baby's name " << student->GetName() << " and he's studying for "
			<< student->GetDirection() << std::endl;
	}

	else
	{

		if (student->IsExcellentStudent())
		{
			std::cout << student->GetName() << " is a very worthy student of the direction " << student->GetDirection();
		}

		else if (GetCurrentMood() == "good") std::cout << "I think that " << student->GetName() <<
			" is trying just as hard to learn as my grandchildren.";

		else if (GetCurrentMood() == "bad") std::cout << student->GetName() << " He's a terrible student! What are his parents doing?!";
	}

}

void Grandmother::AddGrandChildren(Student* child)
{
	GrandChildren.push_back(child);
}

void Grandmother::TellAboutAllChildren()
{
	for (int i = 0; i < GrandChildren.size(); i++) Telling(GrandChildren[i]);
}

void Grandmother::TellAboutRandomChild()
{
	if (GrandChildren.size() == 0) return;

	Telling(GrandChildren[rand() % GrandChildren.size()]);
}

void Grandmother::TellSummaryAboutChildren()
{
	if (GrandChildren.size() == 0) return;

	std::cout << "All of my children are wonderful students and you should know their names! ";
	for (int i = 0; i < GrandChildren.size(); i++) std::cout << GrandChildren[i]->GetName() << ", ";
	std::cout << "!" << std::endl;
}

void Grandmother::TellAboutChildrenInTheSubject(std::string subject)
{
	for (int i = 0; i < GrandChildren.size(); i++)
	{
		if (GrandChildren[i]->AvailabilityOfGradesInSubject(subject)) Telling(GrandChildren[i]);
	}
}

void Grandmother::AddMoods(std::string _mood)
{
	GrandmotherMood.AddMood(_mood);
}

void Grandmother::SetCurrentMood(std::string _mood)
{
	GrandmotherMood.SetMood(_mood);
}

void Grandmother::TellChildrenNames()
{
	for (int i = 0; i < GrandChildren.size(); i++)
	{
		std::cout << GrandChildren[i]->GetName() << " ";
	}
	std::cout << std::endl;
}

std::string Grandmother::GetCurrentMood()
{
	return GrandmotherMood.GetCurrentMood();
}
