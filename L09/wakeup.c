#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void intHandler();

int main( )
{
	signal(SIGALRM,intHandler);
	alarm(5); //알람 함수에 의해 5초 후 SIGALRM 발생함
	printf("loop... \n");

	while (1) {
		sleep(1);
		printf("1 sec... \n");
	}

	printf("End of main \n");
}

void intHandler(int signo){
	printf("Wake up!\n");
	exit(0);
}
