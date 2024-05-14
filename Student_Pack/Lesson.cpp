#include "Lesson.h"

Lesson::Lesson(std::string _LessonName)
{
	LessonName = _LessonName;
}

std::string Lesson::GetLessonName()
{
	return LessonName;
}

void Lesson::AddStudentIntAttendees(Student* student)
{
	Attendees.push_back(student);
}

void Lesson::AddAssesmentToStudent(Teacher* teacher)
{
	teacher->AddMarkToStudent(Attendees[rand() % Attendees.size()],
		LessonName, 1 + rand() % 5);
}
