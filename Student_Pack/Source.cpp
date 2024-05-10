//���������� ����������� ���������� ��� ������ �� ����������.
//� ������ ������� ����� ���������� ����� ����������.���������� ������ ����������� ���
//(�� low coupling, strong cohesion, SOLID, KISS, YAGNI, DRY � ��) ��� ��������� ����������, ���������� ���������������� �� �������.

//���� 7
//� ���������� ������� ���������� ��������.� �������� ����� ���� ����������.
// �������� ����� ����� ��������� �����.�������� ����� ��������� ��������� ������� :
//-���������� � ������ ���� ������ ��� - ������(������� �� ���������� � �� ���� �������� �� ��� ���)
//- ���������� �� ����� ��������� ���� ������ ��� - ������(������� �� ���������� � �� ���� �������� �� ��� ���)
//- ���������� � �����, ��������, ��� ���� ����� �����(������� �� ���������� � �� ���� ��������� ��� � ������� ��� ���)
//- ���������� � ���������� ���� ������(������� �� ���������� � �� ���� ��������� ��� � ������� ��� ���).
// ���� ��� �� ������ ��������, �� �������� �� ������


#include "Lesson.h"
#include "Parent.h"
#include <ctime>

using namespace std;

int main()
{

	srand(time(NULL));

	Lesson l("OOP");

	Teacher t("Georgiy", 28);
	t.AddMoodToTeacher("gOod");
	t.AddMoodToTeacher("Bad");
	t.AddMoodToTeacher("NEuTraL");
	t.SetMood("good");

	Student* s1 = new Student("Yakov", 19, "Progin");
	Student* s2 = new Student("Vokay", 19, "Progin");
	Student* s3 = new Student("Danya", 19, "Progin");
	Student* s4 = new Student("Jimmy", 19, "Progin");
	Student* s5 = new Student("Soul Goodman", 19, "Progin");

	l.AddStudentIntAttendees(s1);
	l.AddStudentIntAttendees(s2);
	l.AddStudentIntAttendees(s3);
	l.AddStudentIntAttendees(s4);
	l.AddStudentIntAttendees(s5);


	for (int i = 0; i < 30; i++)
	{
		l.AddAssesmentToStudent(t);
	}

	Parent* p = new Parent("Olga", 36);
	p->AddMoods("good");
	p->AddMoods("bad");
	p->AddMoods("neutral");
	p->SetCurrentMood("good");
	p->AddChildren(s1);
	p->AddChildren(s2);
	p->AddChildren(s3);

	cout << endl << endl;

	p->TellAboutAllChildren();

	cout << endl;

	p->TellAboutRandomChild();

	cout << endl;

	p->TellSummaryAboutChildren();

	cout << endl;

	p->TellAboutSpecificChild(s4);
}