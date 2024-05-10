//Итеративно разработать приложение для работы со студентами.
//В рамках задания будут появляться новые требования.Необходимо иногда рефакторить код
//(см low coupling, strong cohesion, SOLID, KISS, YAGNI, DRY и тд) под специфику требований, увеличивая сопровождаемость на будущее.

//Этап 7
//В предметной области появляется Родитель.У родителя может быть настроение.
// Родитель может иметь несколько детей.Родитель может выполнять следующие функции :
//-Рассказать о каждом своём ребёнке что - нибудь(зависит от настроения и от того отличник он или нет)
//- Рассказать об одном случайном своём ребёнке что - нибудь(зависит от настроения и от того отличник он или нет)
//- Рассказать в общем, суммарно, обо всех своих детях(зависит от настроения и от того отличники они в среднем или нет)
//- Рассказать о конкретном своём ребёнке(зависит от настроения и от того отличники они в среднем или нет).
// Если это не ребёнок родителя, то сообщить об ошибке


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