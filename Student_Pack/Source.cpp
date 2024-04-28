//Итеративно разработать приложение для работы со студентами.
//В рамках задания будут появляться новые требования.Необходимо иногда рефакторить код
//(см low coupling, strong cohesion, SOLID, KISS, YAGNI, DRY и тд) под специфику требований, увеличивая сопровождаемость на будущее.

//Этап 3
//У преподавателя есть настроение.От настроения преподавателя зависит оценка, которую он поставит студенту.Также на оценку влияет тот, 
// кому преподаватель ставит эту оценку.
//
//Пример формул расчёта итоговой оценки :
//хорошее настроение + отличник = 5
//плохое настроение + отличник = 4 или 5 (равновероятно)
//хорошее настроение + не отличник = 4
//плохое настроение + не отличник = 2 или 3 (равновероятно)

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