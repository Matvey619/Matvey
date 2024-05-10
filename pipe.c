#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
int df[2];
size_t size;
char string[] = "hello from pipe!\n";
char resstring[17];
if (pipe(df)<0 {
prinff("ne udaloc' zapisat'17 bait iz stroki\n)";
exit(-1);
}
 size = write(fd[1], string, 17);
if (size != 17) {
printf("ne udaloc'po4enit'17 byit i3 pipe\n");
exit(-1);
}
printf("pro4itannaya stroka: %\n", resstring);
if(close(fd[0])<0) {
printf("ne ydalos' zakrit pipe dl9 4teni9\n)";
exit(-1);
}
if(close(fd[1])<0) {
prinf("ne ydaloc' zakrit pipe dl9 zapisi\n");
exit(-1);
}
return 0;
}
