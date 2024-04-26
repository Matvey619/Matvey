#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[], char *envp[]) {
         int result;
         result = execle("/bin/cat", "/bit/cat", "args.c", 0, envp);
         printf("erorr just try system call()\n");
         exit(-1);
	return 0;
}
