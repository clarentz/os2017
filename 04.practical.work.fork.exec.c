#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Main before fork()\n");
	
	int pid1 = fork();
	if (pid1 == 0) {
		printf("I am child after fork(), launching ps -ef\n");
		char *args[]= {"/bin/ps", "-ef" , NULL};
	execvp("/bin/ps", args);
	printf("Finished launching ps -ef\n");
	}
	else printf("I am parent after fork(), child is %d\n", pid1);
	
	int pid2 = fork();
	if (pid2 == 0) {
		printf("I am child after fork(), launching free -h\n");
		char *args[]= {"free", "-h" , NULL};
	execvp("free", args);
	printf("Finished launching free -h\n");
	}
	else printf("I am parent after fork(), child is %d\n", pid2);
	
	return 0;
}