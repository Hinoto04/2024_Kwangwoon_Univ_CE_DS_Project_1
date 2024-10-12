#pragma once
#include "SubtitleQueue.h"
#include "SubtitleBST.h"
#include "SectionList.h"
#include "Subtitle.h"
#include <fstream>
#include <string>
using namespace std;

class Manager
{
private:

	ifstream		fcmd;
	ofstream		flog;

	SubtitleQueue q;

public:
	Manager(): q(nullptr);
	~Manager();

	void Run(const char* command);

	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);

	// LOAD
	void load();
	// QPOP
	void qpop();
	// PRINT
	void print();
	void print(int number);
	// SECTION
	void section(int number, int start, int end); //start, end is time in seconds
	// DELETE
	void del(int mode, int time); //time is time in seconds
	//mode EQUAL -> 0
	//mode UNDER -> -1
};
