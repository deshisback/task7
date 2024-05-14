//Итеративно разработать приложение для работы со студентами.
//В рамках задания будут появляться новые требования.Необходимо иногда рефакторить код
//(см low coupling, strong cohesion, SOLID, KISS, YAGNI, DRY и тд) под специфику требований, увеличивая сопровождаемость на будущее.

//Этап 8
//В предметной области появляется Собрание.На собрании участвуют Преподаватели, Родители.
// Они обсуждают все прошедшие занятия и родители по каждому из своих детей, которые получали за эти занятия хотя бы одну оценку,
// высказываются "о конкретном своём ребёнке".Если на собрании нет преподавателя, который проводил Занятие, то эти 
// выставленные оценки не учитываются при необходимости обсуждения ребёнка.
// Если на собрании нет родителя ребёнка, то список таких детей формируется в конце собрания и должен быть оглашён.
// 
//Архитектурный тест 8
//Архитектура позволяет проводить несколько собраний по различному набору Занятий, меняя состав преподавателей и родителей.


#include "Lesson.h"
#include "Meeting.h"
#include <ctime>

using namespace std;

int main()
{

	srand(time(NULL));

	Lesson l("OOP");
	Lesson l2("PE");
	Lesson l3("Math");
	Meeting m;
	ParentPseudoInterface ppi;

	Teacher* t = new Teacher("Georgiy", 28);
	t->AddMoodToTeacher("gOod");
	t->AddMoodToTeacher("Bad");
	t->AddMoodToTeacher("NEuTraL");
	t->SetMood("good");
	t->SetTeacherSubject("OOP");
	
	Teacher* t1 = new Teacher("Vladimir", 31);
	t1->AddMoodToTeacher("gOod");
	t1->AddMoodToTeacher("Bad");
	t1->AddMoodToTeacher("NEuTraL");
	t1->SetMood("bad");
	t1->SetTeacherSubject("PE");

	Teacher* t2 = new Teacher("Anatoliy", 27);
	t2->AddMoodToTeacher("gOod");
	t2->AddMoodToTeacher("Bad");
	t2->AddMoodToTeacher("NEuTraL");
	t2->SetMood("neutral");
	t2->SetTeacherSubject("Math");

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

	l2.AddStudentIntAttendees(s1);
	l2.AddStudentIntAttendees(s2);
	l2.AddStudentIntAttendees(s3);
	l2.AddStudentIntAttendees(s4);
	l2.AddStudentIntAttendees(s5);

	l3.AddStudentIntAttendees(s1);
	l3.AddStudentIntAttendees(s2);
	l3.AddStudentIntAttendees(s3);
	l3.AddStudentIntAttendees(s4);
	l3.AddStudentIntAttendees(s5);


	for (int i = 0; i < 5; i++)
	{
		l.AddAssesmentToStudent(t);
	}

	for (int i = 0; i < 5; i++)
	{
		l2.AddAssesmentToStudent(t1);
	}

	for (int i = 0; i < 5; i++)
	{
		l3.AddAssesmentToStudent(t2);
	}

	Parent* p = new Parent("Olga", 36);
	p->AddMoods("good");
	p->AddMoods("bad");
	p->AddMoods("neutral");
	p->SetCurrentMood("good");
	p->AddChildren(s1);
	p->AddChildren(s2);
	p->AddChildren(s3);

	Parent* p2 = new Parent("Kristina", 46);
	p2->AddMoods("good");
	p2->AddMoods("bad");
	p2->AddMoods("neutral");
	p2->SetCurrentMood("neutral");
	p2->AddChildren(s4);
	p2->AddChildren(s5);

	ppi.AddParentToList(p);
	ppi.AddParentToList(p2);

	m.AddParentToMeeting(p);
	m.AddParentToMeeting(p2);
	m.AddTeacherToMeeting(t);
	m.AddTeacherToMeeting(t1);
	m.AddTeacherToMeeting(t2);

	m.ParentTellAboutChild();
	cout << endl;
	m.ListOfChildrenOfAbsentParent(ppi);


}