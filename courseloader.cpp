#include "courseloader.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

CourseLoader::CourseLoader()
{

}

//Save a new record
void CourseLoader::save(Course course, int t, std::string filename){
	std::ofstream trackFile(filename);
	if(trackFile.is_open()){
		trackFile << course.getStart().x << " " << course.getStart().y << " " << t;
		for (int i = 0; i < course.width*course.height; i++){
			if(i % course.width == 0){
				trackFile << std::endl;
			}
			trackFile << course.asString()[i];


		}
		trackFile.close();
	} else {
		std::cout << "Unable to open file!";
	}
}

//Load a map from a file
//The file must be in the following format:
//startX startY record
//mapdata
Course *CourseLoader::load(std::string filename){
	std::cout << filename;
	std::string line; //One line on the track file
	std::vector<Tile> newMap; //Map tiles
	std::ifstream trackFile(filename); //Track file
	int width = 0;
	int height = 0;
	int rec = 0;
	Point *start = NULL;
	if(trackFile.is_open()){
		int y = 0;
		while (std::getline(trackFile, line)){
			//Map information on the first line
			if(y == 0){
				std::stringstream ss(line);
				std::vector<int> info;
				int tmp;
				while(ss >> tmp){
					info.push_back(tmp);
				}
				//Check if we have the right amount of data
				if(info.size() != 3){
					std::cout << "Bad map info!" << std::endl;
					return NULL;
				}
				start = new Point(info[0], info[1]);
				rec = info[2];
			} else {
				//Reading map data
				for(unsigned long long i = 0; i < line.length(); i++){
					char terrain = line[i];
					Point *loc = new Point(i,y-1);
					Tile *t = new Tile(*loc, terrain);
					delete loc;
					newMap.push_back(*t);

				}
				height++;
				width = line.length();
			}
		y++;
		}
		trackFile.close();
	} else {
		std::cout << "Unable to open file!" << std::endl;
		return NULL;
	}
	newMap.shrink_to_fit();
	Course *course = new Course(newMap,width,height, *start, rec);
	delete start;
	return course;
}

//Default map when a track file is not provided
Course *CourseLoader::load(){
	std::vector<std::string> tmpMap;
	tmpMap.push_back("#################################........################################################........#######################");
	tmpMap.push_back("###############.......................................................................................##################");
	tmpMap.push_back("######...................................................................................................###############");
	tmpMap.push_back("###.........................................................................................................############");
	tmpMap.push_back("##.....................................................................................##############........###########");
	tmpMap.push_back("#...............................######################################################################.......###########");
	tmpMap.push_back("##.........##############################################################################################.....##########");
	tmpMap.push_back("#......##################################################################################################......#########");
	tmpMap.push_back("#......##################################################################################################.......########");
	tmpMap.push_back("#......#######################################################################################..................########");
	tmpMap.push_back("#.......#############################..........................................................................#########");
	tmpMap.push_back("##......######################................................................................................##########");
	tmpMap.push_back("##........##################...............................................................................#############");
	tmpMap.push_back("####......###############..............#################################################################################");
	tmpMap.push_back("####.......#############.........#######################################################################################");
	tmpMap.push_back("#####......#############.......#########################################################################################");
	tmpMap.push_back("#####.......############.....########################....###############################################################");
	tmpMap.push_back("######......############.....######################..........##################..................#######################");
	tmpMap.push_back("######.....#############.....###################...............#############........................####################");
	tmpMap.push_back("######.....#############......################..................###########............................#################");
	tmpMap.push_back("#####......#############.......##############........#####......###########...........########..........################");
	tmpMap.push_back("###........##############............................#######......########.....##################.........##############");
	tmpMap.push_back("###......#################.........................#########.......######......#####################........############");
	tmpMap.push_back("###......##################.......................###########........###......########################.......###########");
	tmpMap.push_back("###.....######################................#################..............###########################.......#########");
	tmpMap.push_back("##......##########################........######################.............############################......#########");
	tmpMap.push_back("##......#########################################################...........#############################.......########");
	tmpMap.push_back("##......###########################################################........###############################......########");
	tmpMap.push_back("##......##################################################################################################FFFFFF########");
	tmpMap.push_back("##......##################################################################################################FFFFFF########");

	std::vector<Tile> newMap;

	//Make map tiles
	for(unsigned long long i = 0; i < tmpMap.size(); i++){
		for(unsigned long long j = 0; j < tmpMap[i].length(); j++){
			std::string row = tmpMap[i];
			char terrain = row[j];
			Point *loc = new Point(j,i);
			Tile *t = new Tile(*loc, terrain);
			delete loc;
			newMap.push_back(*t);
		}
	}
	newMap.shrink_to_fit();

	Point *start = new Point(4,29);
	Course *course = new Course(newMap,tmpMap[0].length(),tmpMap.size(), *start);
	delete start;
	return course;
}
