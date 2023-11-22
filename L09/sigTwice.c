#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void intHandler();
void intHandler2();

/* 인터럽트 시그널을 처리한다. */
int main( )
{
	signal(SIGINT, intHandler);
	while (1)
		pause();
	printf("End of main \n");
}

void intHandler(int signo)
{
	printf("SIGINT \n");
	printf("Sig No.: %d\n", signo);
	//exit(0);
	signal(SIGINT, intHandler2);
}
void intHandler2(int signo){
	exit(0);
}
