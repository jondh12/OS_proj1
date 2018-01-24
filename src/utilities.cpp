/*
 * utilities.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: jon
 */
#include "../includes/utilities.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

typedef std::vector<process_stats> vector;
vector v;

//Sorts the vector v by cpu time
bool sortCPU(process_stats a, process_stats b) {
	return a.cpu_time < b.cpu_time;
	//Sorts the vector v by start time
}
bool sortStart(process_stats a, process_stats b) {
	return a.start_time < b.start_time;
	//Sorts the vector v by process number
}
bool sortProcess(process_stats a, process_stats b) {
	return a.process_number < b.process_number;

}


//loads data from the filename and returns a int code detailing sucess or not
int loadData(const char* filename) {
	std::ifstream myfile;
	myfile.open(filename);
	if (myfile.is_open()) {
		std::string line;
		while (getline(myfile, line)) {
			std::string copyOfToken = line;
			bool bToParse = true;
			int data[3];
			int indexOfArray = 0;

			while (bToParse) {

				int indexOfDelimeter = 0;
				indexOfDelimeter = copyOfToken.find(CHAR_TO_SEARCH_FOR);
				std::string temp = copyOfToken.substr(0, indexOfDelimeter);
				data[indexOfArray] = std::stoi(temp);
				indexOfArray++;
				copyOfToken = copyOfToken.substr(indexOfDelimeter + 1,
						copyOfToken.size());
				if (indexOfArray == 3) {
					bToParse = false;
				}

			}
			//Add new process_stats struct to vector v
			process_stats newStats = { data[0], data[1], data[2] };
			v.push_back(newStats);

		}
		myfile.close();
		return SUCCESS;
	} else {
		return COULD_NOT_OPEN_FILE;
	}

}

// adds item to write out to the file
std::string addItem(int a, bool addComma) {
	std::string toReturn;
	toReturn += std::to_string(a);
	if (addComma) {
		toReturn += ',';
	}
	return toReturn;
}

// writes contents of data to the filename
int saveData(const char* filename) {
	std::ofstream myfile;
	myfile.open(filename);
	if (myfile.is_open()) {
		while (v.size() > 0) {
			process_stats p = getNext();
			std::string toWrite;
			toWrite += addItem(p.process_number, true);
			toWrite += addItem(p.start_time, true);
			toWrite += addItem(p.cpu_time, false);
			if (v.size() == 0) {
				myfile << toWrite;
			} else {
				myfile << toWrite << '\n';
			}
		}
	} else {
		return COULD_NOT_OPEN_FILE;
	}
	return SUCCESS;

}
// sorts the data based upon the sort order given
void sortData(SORT_ORDER mySortOrder) {
	switch (mySortOrder) {
	case CPU_TIME:
		std::sort(v.begin(), v.end(), sortCPU);
		break;
	case PROCESS_NUMBER:
		std::sort(v.begin(), v.end(), sortProcess);
		break;
	case START_TIME:
		std::sort(v.begin(), v.end(), sortStart);
		break;
	}

}
// returns the first item of the data and removes it from storage
process_stats getNext() {
	process_stats temp = v.at(0);
	v.erase(v.begin());
	return temp;
}

