#ifndef COURSELOADER_H
#define COURSELOADER_H


#include "course.h"
class CourseLoader
{
public:
	CourseLoader();
	Course *load();
	Course *load(std::string filename);
	void save(Course course, int t, std::string filename);
};

#endif // COURSELOADER_H
