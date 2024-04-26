#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[], char *envp[]) {
         pid_t result, procid, parentid;
	printf("poroshdaem dochernyi procec\n");
result = fork();
if(result < 0) {
printf("oshibka pri vipolnenii fork()\n");
exit(-1);
}
else if(result==0) {
procid = getpid();
parentid = getppid();
printf("id tekushego proccesa; %d\n", procid);
printf("result; %d\n", parentid);
printf("rodprocces; %d\n", result);
execle("./args.out", " ./args.out", "args.c", 0, envp);
printf("erorr exec()\n");
exit(-1);
}
else {
procid = getpid();
parentid = getppid();
printf("id tekushego proccesa; %d\n", procid);
printf("result; %d\n", parentid);
printf("rodprocces; %d\n", result);
printf("erorr exec()\n");
}
return 0;
}
