//============================================================================
// Name        : proj1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../includes//utilities.h"
using namespace std;

int main() {
	//test sorting by process number
	loadData("./out/testIn.txt");
	sortData(PROCESS_NUMBER);
	saveData("./out/sortedProcess.txt");
	//test sorting by CPU time
	loadData("./out/testIn.txt");
	sortData(CPU_TIME);
	saveData("./out/sortedCPU.txt");
	//test sorting by Start time
	loadData("./out/testIn.txt");
	sortData(START_TIME);
	saveData("./out/sortedStart.txt");
}
