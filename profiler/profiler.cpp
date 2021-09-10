//============================================================================
// Name        : profiler.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

#include <unistd.h>
#include <time.h>

typedef struct
{
	const char* msg;
	int time;
} TimeStamp;

class Profiler
{
	private:
		TimeStamp _timeStamps[1000];
		int _index;
	public:
		Profiler();
		void AddTimeStamp(const char* msg);
		void SaveProfileLog();
};


Profiler::Profiler()
{
	_index = 0;
}

void Profiler::AddTimeStamp(const char* msg)
{
	_timeStamps[_index].time = time(NULL);
	_timeStamps[_index].msg  = msg;
	_index++;
}

void Profiler::SaveProfileLog()
{
	ofstream csvfile;
	csvfile.open ("profile.csv");

	for (int i = 0; i < _index; i++)
	{
		csvfile << _timeStamps[i].time << "," << _timeStamps[i].msg << endl;
	}

	csvfile.close();
}

// =======================================================
//#define PROF profiler.AddTimeStamp(__FUNCTION__);
#define PROF profiler.AddTimeStamp(__FUNCTION__);
//#define PROF
// =======================================================

Profiler profiler;

void function_1()
{
	PROF;
	sleep(1);
	PROF;
}

void function_2()
{
	PROF;
	sleep(2);
	PROF;
}

void function_3()
{
	PROF;
	sleep(3);
	PROF;
}

void function_4()
{
	profiler.AddTimeStamp("F4 start");
	function_1();
	function_2();
	function_3();
	profiler.AddTimeStamp("F4 end");
}

int main()
{
	cout << "Start" << endl;
	function_1();
	function_2();
	function_3();
	function_4();
	cout << "Finish" << endl;

	profiler.SaveProfileLog();
	cout << "Profile log saved" << endl;


	return 0;
}
