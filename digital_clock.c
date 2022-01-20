#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()

{
	int hours,minutes,seconds;
	struct timespec ts;
	ts.tv_sec = 1;
    	ts.tv_nsec = 0;
	printf("Set time (HH,MM,SS): \n");
	scanf("%d%d%d",&hours,&minutes,&seconds);
	if(hours > 24 || minutes > 60 || seconds > 60)
	{
		printf("Error\n");
		exit(0);
	}
	while(1)
	{
		seconds++;
		if(seconds > 59)
		{
			minutes++;
			seconds = 0;
		}
		if(minutes > 59)
		{
			hours++;
			minutes = 0;
		}
		if(hours > 24)
		{
			hours = 1;
		}
		printf("\n%02d:%02d:%02d",hours,minutes,seconds);
		nanosleep(&ts, NULL);
		system("clear");
	}
}
