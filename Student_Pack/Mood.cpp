#include "Mood.h"

void Mood::AddMood(std::string _mood)
{

	std::for_each(_mood.begin(), _mood.end(), [](char& c)
		{
			c = ::tolower(c);
		}
	);

	if (std::find(Moods.begin(), Moods.end(), _mood) != Moods.end())
	{
		return;
	}

	else
	{
		Moods.push_back(_mood);
	}

}

void Mood::SetMood(std::string _mood)
{

	if (Moods.empty()) return;

	else if (std::find(Moods.begin(), Moods.end(), _mood) != Moods.end())
	{
		CurrentMood = _mood;
	}

	else return;

}

void Mood::RandomUpdateMood()
{

	if (Moods.empty()) return;

	else
	{
		CurrentMood = Moods[rand() % Moods.size()];
	}

}

std::string Mood::GetCurrentMood()
{
	return CurrentMood;
}
