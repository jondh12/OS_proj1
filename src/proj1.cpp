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

	loadData("./out/testIn.txt");
	sortData(PROCESS_NUMBER);
	saveData("./out/testOut.txt");
}
