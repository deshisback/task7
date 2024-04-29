//»теративно разработать приложение дл€ работы со студентами.
//¬ рамках задани€ будут по€вл€тьс€ новые требовани€.Ќеобходимо иногда рефакторить код
//(см low coupling, strong cohesion, SOLID, KISS, YAGNI, DRY и тд) под специфику требований, увеличива€ сопровождаемость на будущее.

//Ётап 5
//≈сть преподаватели, которые став€т 5, вне зависимости от настроени€ и от того, кому они став€т оценку.
//
//јрхитектурный тест 5
//јрхитектура предусматривает по€вление и тех преподавателей, которые будут всегда ставить 2.

#include "Lesson.h"
#include <ctime>

using namespace std;

int main()
{

	srand(time(NULL));

	Lesson l("OOP");

	Teacher t("Georgiy", 28);
	t.SetMood("good");
	t.SetState("gnida");

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