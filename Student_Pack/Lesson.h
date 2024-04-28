#pragma once
#include "Teacher.h"

class Lesson
{

private:

	std::string LessonName;
	std::vector<Student*> Attendees;

public:

	Lesson(std::string _LessonName);

	std::string GetLessonName();

	void AddStudentIntAttendees(Student* student);

	void AddAssesmentToStudent(Teacher teacher);

};

