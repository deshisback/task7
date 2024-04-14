//Итеративно разработать приложение для работы со студентами.
//В рамках задания будут появляться новые требования.Необходимо иногда рефакторить код
//(см low coupling, strong cohesion, SOLID, KISS, YAGNI, DRY и тд) под специфику требований, увеличивая сопровождаемость на будущее.

//Этап 2
//В предметной области появляется Преподаватель, который может выставлять студентам отметки.
//
//Архитектурный тест 2
//Система должна позволять добавлять новых преподавателей.Преподаватель может выставлять оценки произвольным студентам

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Human
{

private:

	string Name;
	unsigned int Age;

public:

	int GetAge()
	{
		return Age;
	}

	string GetName()
	{
		return Name;
	}

	Human(string _Name, int _Age)
	{
		Name = _Name;
		Age = abs(_Age);
	}

};

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

class Student : public Human
{

private: 

	string Direction;
	vector<Subject> marks;

public:

	Student(string _Name, int _Age, string _Direction) : Human(_Name, _Age)
	{
		Direction = _Direction;
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

class Teacher: public Human
{

public:

	Teacher(string _Name, int _Age) : Human(_Name, _Age) {};

	void AddMarkToStudent(Student student, string subject, int assesment)
	{
		student.AddMark(subject, assesment);
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

	Teacher t("Dmitry", 25);
}