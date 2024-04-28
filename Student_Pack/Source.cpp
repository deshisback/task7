//���������� ����������� ���������� ��� ������ �� ����������.
//� ������ ������� ����� ���������� ����� ����������.���������� ������ ����������� ���
//(�� low coupling, strong cohesion, SOLID, KISS, YAGNI, DRY � ��) ��� ��������� ����������, ���������� ���������������� �� �������.

//���� 3
//� ������������� ���� ����������.�� ���������� ������������� ������� ������, ������� �� �������� ��������.����� �� ������ ������ ���, 
// ���� ������������� ������ ��� ������.
//
//������ ������ ������� �������� ������ :
//������� ���������� + �������� = 5
//������ ���������� + �������� = 4 ��� 5 (�������������)
//������� ���������� + �� �������� = 4
//������ ���������� + �� �������� = 2 ��� 3 (�������������)

#include "Lesson.h"
#include <ctime>

using namespace std;

int main()
{

	srand(time(NULL));

	Lesson l("OOP");

	Teacher t("Georgiy", 28);
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

	s1->PrintMarks();
	s2->PrintMarks();
	s3->PrintMarks();
	s4->PrintMarks();
	s5->PrintMarks();
}