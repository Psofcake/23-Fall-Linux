#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void intHandler();


/* 인터럽트 시그널을 처리한다. */
int main( )
{
	signal(SIGINT, SIG_IGN);
	while (1)
		pause();
	printf("End of main \n");
}

void intHandler(int signo)
{
	printf("SIGINT \n");
	printf("Sig No.: %d\n", signo);
	exit(0);
}

//ctrl C를 눌러도 꺼지지 않기 때문에 ctrl Z를 입력하고 kill-9 %1를 함.
