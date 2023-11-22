#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int child_id;
void intHandler();
void intHandler2();
void intHandler3();

void gugudan(){
	for(int i=1; i<=20; i++){
		for(int j=1; j<20; j++){
			printf("%d x %d = %d\n", i, j, i*j);
		}
		if(i==9)
			signal(SIGINT,intHandler3);
		sleep(1);
	}
}

int main(){
	int pid;
	int count = 0;
	int x=1;
	int y=1;

	pid = fork();
	if(pid==0){ //child
		//구구단 출력;
			signal(SIGINT,intHandler2);
			gugudan();
			pause();
	}else{ //parent
		child_id = pid;
		signal(SIGINT,intHandler);
		wait();
	}
	return 0;
}

void intHandler(int signo){
	kill(child_id, SIGINT);
}
void intHandler2(int signo){
	printf("cannot terminate...\n");
}
void intHandler3(int signo){
	kill(-getppid(), SIGKILL);
			//그룹에 속한 모든 멤버에게 시그널
}
