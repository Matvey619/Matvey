#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int semid;
	char pathname[] = "for_ipc.ipc";
	key_t key;
	struct sembuf mybuf;
	if((key = ftok(pathname, 0)) < 0) {
		printf("ne ydaloc' gener key ipc\n");
		exit(-1);
	}
	if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
		printf("ne ydaloc' polu4it deckreptor massiva semaforov");
		exit(-1);
	}
	mybuf.sem_op = -1;
	mybuf.sem_flg = 0;
	mybuf.sem_num = 0;
	printf("oshidanie razblokirovki proccesa\n");
	if(semop(semid, &mybuf, 1) < 0) {
		printf("ne ydaloc' get operaci nad cemaformom\n");
		exit(-1);
	}
	printf("tekushi' procec razblok\n");
	return 0;
}
