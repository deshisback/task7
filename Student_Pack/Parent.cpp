#include "Parent.h"

void Parent::Tellling(int i)
{

	if (Children[i]->IsExcellentStudent())
	{
		std::cout << "My beautiful baby's name " << Children[i]->GetName() << " and he's studying for "
			<< Children[i]->GetDirection() << std::endl;
	}

	else if (GetCurrentMood() == "good") std::cout << "My baby's name " << Children[i]->GetName() << std::endl;

	else if (GetCurrentMood() == "bad") std::cout << "My baby's name " << Children[i]->GetName()
		<< " and he's studying pretty badly" << std::endl;

	else std::cout << "Who is this?" << std::endl;

}

void Parent::AddChildren(Student* child)
{
	Children.push_back(child);
}

void Parent::TellAboutAllChildren()
{

	for (int i = 0; i < Children.size(); i++)
	{
		Tellling(i);
	}

}

void Parent::TellAboutRandomChild()
{

	int RandomChild = rand() % Children.size();
	Tellling(RandomChild);

}

void Parent::TellSummaryAboutChildren()
{

	double summary = 0;

	for (int i = 0; i < Children.size(); i++)
	{
		summary += Children[i]->GetAverageGrade();
	}

	summary /= Children.size();

	for (int i = 0; i < Children.size(); i++)
	{
		if (summary >= 4.5)
		{
			std::cout << "My beautiful baby's name " << Children[i]->GetName() << " and he's studying for "
				<< Children[i]->GetDirection() << std::endl;
		}

		else if (GetCurrentMood() == "good") std::cout << "My baby's name " << Children[i]->GetName() << std::endl;

		else if (GetCurrentMood() == "bad") std::cout << "My baby's name " << Children[i]->GetName()
			<< " and he's studying pretty badly" << std::endl;

		else std::cout << "Who is this?" << std::endl;
	}

	std::cout << "On average, they study for " << summary << std::endl;
}

void Parent::TellAboutSpecificChild(Student* student)
{

	for (int i = 0; i < Children.size(); i++)
	{

		if (Children[i] == student)
		{
			Tellling(i);
			return;
		}

	}

	std::cout << "Mistake 1: (That's not my baby)" << std::endl;

}

void Parent::TellAboutChildrenInTheSubject(std::string subject)
{

	for (int i = 0; i < Children.size(); i++)
	{
		if (Children[i]->AvailabilityOfGradesInSubject(subject)) TellAboutSpecificChild(Children[i]);
	}

}

void Parent::AddMoods(std::string _mood)
{
	ParentMood.AddMood(_mood);
}

void Parent::SetCurrentMood(std::string _mood)
{
	ParentMood.SetMood(_mood);
}

void Parent::TellChildrenNames()
{
	for (int i = 0; i < Children.size(); i++)
	{
		std::cout << Children[i]->GetName() << " ";
	}
	std::cout << std::endl;
}

std::string Parent::GetCurrentMood()
{
	return ParentMood.GetCurrentMood();
}

Student* Parent::GetChild(int i)
{
	if (i < 0 || i > Children.size()) return nullptr;
	else return Children[i];
}
