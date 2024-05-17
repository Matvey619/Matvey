#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
int fd, result;
size_t size;
char string[] = "Gr.3.124.2.23", resstring[13];
char name[] = "fifo.fifo";
/*	if(mknod(name, S_IFIFO | 0666, 0)<0) {
printf("ne udaloc' create FIFO/n");
exit(-1);
}
*/ 
if((result = fork()) < 0) {
printf("ne udaloc' create do4eryi procecc/n");
exit(-1);
}
else if(result > 0) {
if((fd = open(name, O_WRONLY)) < 0) {
printf("ne udaloc' zapicat' str celicom");
exit(-1);
}
size = write(fd, string, 13);
if(size !=13) {
printf("ne udaloc' zapicat' str celicom");
exit(-1);
}
close(fd);
printf("stroka zapicano v FIFO, procec roditel' zavershaet job/n");
exit(-1);
}
else {
if((fd = open(name, O_RDONLY)) < 0) {
printf("ne udaloc' open FOFO fo Write");
exit(-1);
}
size = read(fd, resstring, 13);
if (size != 13) {
printf("ne udaloc' pro4itat' vsu str");
exit(-1);
}
printf("deo4 proc write str: %s\n", resstring);
close(fd);
}
return 0;
}
