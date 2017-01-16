#pragma once
#include <string>
using namespace std;

typedef unsigned char byte;
void f(string);

class GTime
{
	pair<byte,byte>	gtime;
	size_t day;
  private:
	bool checkTime();
	bool checkOverflow();
	void convertTime();
	void convertTime(int , int);
	void Init(int, int);
  public:
	GTime(int , int );
	GTime(byte, byte);
	string getTime();
	void printTime();
	void add(int t);
	GTime operator+(GTime& l) {return GTime(l.gtime.first + gtime.first, l.gtime.second + gtime.second);};
};
