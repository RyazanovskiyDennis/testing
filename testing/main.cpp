#include <iostream>
#include "func.hpp"
#include <ctime>
#include <unistd.h>
using namespace std;

int main (void)
{
	GTime t(11,48),t2(8,33), t3(4,0);
/*	for (int i(0);i<100;i++)
	{
		t.printTime();	
		t.add(1);
		sleep(1);
	}*/
	t = t+t2;
	t = t+t3;
	t.printTime();
	return 0;
}
