#include <iostream>
#include <time.h>

void getTime(){
	time_t mytime;
	time(&mytime);
	printf("\n%s", ctime(&mytime));
}