#include "func.hpp"
#include <iostream>
#include <utility>
#include <cstdio>
using namespace std;

void f (string s)
{
	cout << s << endl;
}

bool GTime::checkTime()
{
	bool res = checkOverflow();
	if (res) convertTime();
	return res;
}

bool GTime::checkOverflow()
{
	return gtime.first >= 60 || gtime.second >= 60;
}

void GTime::convertTime()
{
	convertTime(gtime.first, gtime.second);
}

void GTime::convertTime(int f, int s)
{
	gtime.second = s % 60;
	f += s / 60;
	day += f / 24;
	gtime.first = f % 24;
}

string GTime::getTime()
{
	string r;
	char tmp[3];
	snprintf(tmp,4,"%3lu",day);
	r+= tmp;
	r+=" day, ";
	snprintf(tmp,3,"%02d",gtime.first);
	r+= tmp;
	r+=':';
	snprintf(tmp,3,"%02d",gtime.second);
	r+=tmp;
	//printf("%d:%d\n",gtime.first, gtime.second);
	return r;
}

void GTime::printTime()
{
	cout << "Current time is: " << getTime() <<endl;
}
void GTime::Init(int f, int s)
{
	day = 0;
	gtime.first = gtime.second = 0;
	convertTime(f,s);
	//printTime();
}

GTime::GTime(int f, int s)
{
	Init(f,s);	
}

GTime::GTime(byte f, byte s)
{
	Init(f,s);
}

void GTime::add(int t=1)
{
	gtime.second+=t;	
	checkTime();
}
/*
GTime GTime::operator+(GTime& l)
{
	return GTime(l.gtime.first + gtime.first, l.gtime.second + gtime.second);
}*/
