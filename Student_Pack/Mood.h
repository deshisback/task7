#pragma once
#include <string>
#include <vector>
#include <algorithm>

class Mood
{

private:

	std::vector<std::string> Moods;
	std::string CurrentMood = "";

public:

	void AddMood(std::string _mood);

	void SetMood(std::string _mood);

	void RandomUpdateMood();

	std::string GetCurrentMood();

};

