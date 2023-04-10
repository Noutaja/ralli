#include "courseloader.h"
#include "game.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
	CourseLoader loader = CourseLoader();
	Course *course;

	if(argc > 1){
		course = loader.load(argv[1]);
	}
	else {
		course = loader.load("default.trk");
		//Fallback map if all else fails
		if (course == NULL)
			course = loader.load();
	}

	if(course == NULL){
		std::cout << "No course loaded!" << std::endl;
		system("pause");
		return 0;
	}

	//Set console to the right size
	std::string tmpStr = "MODE CON COLS=";
	tmpStr += std::to_string(course->width);
	tmpStr += " LINES=";
	tmpStr += std::to_string(course->height+3);
	const char *setScreensize = tmpStr.c_str();
	system(setScreensize);

	Game game = Game(*course);
	int time = game.run();
	if(argc > 0 && time > 0){
		if(time < course->record){
			std::cout << "New record! " << time << " turns!" << std::endl;
			if(argc > 1){
				loader.save(*course, time, argv[1]);
			}
			else {
				loader.save(*course, time, "default.trk");
			}

		} else {
			std::cout << "You finished in " << time << " turns! The current record is " << course->record << " turns." << std::endl;
		}

	}
	system("pause");
    return 0;
}

