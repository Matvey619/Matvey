#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main() {
int *array;
int shmid;
int new = 1;
char pathname[] = "for_ipc.ipc";
key_t key;
if((key = ftok(pathname, 0)) < 0) {
printf("ne udaloc' gen key/n");
exit(-1);
}
if((shmid = shmget(key, 3*sizeof(int), 0666 | IPC_CREAT | IPC_EXCL)) < 0) {
if (errno != EEXIST) {
printf("ne udaloc'  sodat' elemen razdel memory\n");
exit(-1);
}
else {
if((shmid = shmget(key, 3*sizeof(int), 0)) < 0) {
printf("ne udaloc' search razdel memory\n");
exit(-1);
}
new = 0;
}
}
if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)) {
printf("ne udaloc' cinnect segment k adres prostranstvu tekuchego rpocecca\n");
exit(-1);
}
if (new) {
array[0] = 1;
array[1] = 0;
array[2] = 1;
}
else {
array[0] += 1;
array[2] += 1;
}
printf("progamma 1 zapuskalac' %d ra(a), programma 2 - %d rad(a), vsego zapuskov - %d\n",array[0], array[1], array[2]);
if(shmdt(array) < 0) {
printf("ne udaloc' kick segment is adrecnogo prostranstva tekychego procecca\n)");
exit(-1);
} 
return 0;
}
