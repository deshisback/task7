//Итеративно разработать приложение для работы со студентами.
//В рамках задания будут появляться новые требования.Необходимо иногда рефакторить код
//(см low coupling, strong cohesion, SOLID, KISS, YAGNI, DRY и тд) под специфику требований, увеличивая сопровождаемость на будущее.

//Этап 1
//В предметной области есть Студент, студент может получать отметки.
//
//Необходимо произвольной формулой вычислить является ли студент отличником.
//
//Архитектурный тест 1
//Система должна позволять добавлять новых студентов, выставлять им оценки, определять кто отличник, а кто нет

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Subject
{

private:

	string SubjectName;
	vector<int> SubjectAssesments;

public:

	Subject()
	{
		SubjectName = "";
	}

	Subject(string _SubjectName, vector<int> AssesmentArray)
	{
		SubjectName = _SubjectName;
		SubjectAssesments.resize(AssesmentArray.size());
		SubjectAssesments = AssesmentArray;
	}

	Subject(string _SubjectName)
	{
		SubjectName = _SubjectName;
	}

	string GetName()
	{
		return SubjectName;
	}

	void AddAssesment(int Assesment)
	{
		SubjectAssesments.push_back(Assesment);
	}

	double AverageSummary()
	{
		double summary = 0;
		int count = SubjectAssesments.size() - 1;
		double result = 0;

		for (int i = 0; i <= count; i++)
		{
			summary += SubjectAssesments[i];
		}

		result = summary / count;

		return result;
	}

};

class Student
{

private:

	string Name;
	unsigned int Age;
	string Direction;
	vector<Subject> marks;

public:

	Student(string _Name, int _Age, string _Direction)
	{
		Name = _Name;
		_Age = abs(_Age);
		Age = _Age;
		Direction = _Direction;
	}

	int GetAge()
	{
		return Age;
	}

	string GetName()
	{
		return Name;
	}

	string GetDirection()
	{
		return Direction;
	}

	void AddMark(string subject, int Assesment)
	{

		for (int i = 0; i < (int)marks.size(); i++)
		{
			if (marks[i].GetName() == subject)
			{
				marks[i].AddAssesment(Assesment);
				return;
			}
		}

		Subject sub(subject);
		sub.AddAssesment(Assesment);
		marks.push_back(sub);
		return;

	}

	bool IsExcellentStudent()
	{

		int count = marks.size();

		if (count == 0) return true;

		double sum = 0;

		for (int i = 0; i < count; i++)
		{
			sum += marks[i].AverageSummary();
		}

		double result = sum / count;

		if (result <= 4.5) return false;
		else return true;
	}

};

int main()
{
	Student s("Yakov", 18, "Proginzh");
	Student b("Georgiy", 19, "Lingvistika");
	
	for (int i = 0; i < 5; i++)
	{
		s.AddMark("OOP", 5);
		s.AddMark("Language", 5);
		s.AddMark("Math", 5);
		b.AddMark("OOP", i);
		b.AddMark("Language", i);
		b.AddMark("Math", i);
	}

	string sname = s.GetName();
	string bname = b.GetName();

	cout << "Is " << sname << " an excellent student ? Answer: " << s.IsExcellentStudent() << endl; 
	cout << "Is " << bname << " an excellent student ? Answer: " << b.IsExcellentStudent() << endl;
}