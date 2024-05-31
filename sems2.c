#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main() { 
        int semid; //IPC-deckriptor dl9 zna4enie massiva cemamorfov
        char pathname[] = "for_ipc.ipc"; //name file, c pomo4'u kotorogo hen ipc-key 
        key_t key; //peremenna dl9 save ipc_kye
        struct sembuf mybuf; //srukt date, zaday4ay operacii nad opredelennim cemaforom
        if((key = ftok(pathname, 0)) < 0) {
                printf("ne ydaloc' gener key ipc\n");
                exit(-1);
        }
//procces send doctupa k massivy cemaforov dl9 konkretnogo ipc-key
//esli massiva cemaforov ne cu4ectvuet, to pitaevc9 ego creat
               if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
                printf("ne ydaloc' polu4it deckreptor massiva semaforov");
                exit(-1);
}
		printf("ne ydaloc' polu4it deckreptor massiva semaforov");
	mybuf.sem_op = 1; //kodirovanie operacii D(semid1,1)
	mybuf.sem_flg = 0;
        mybuf.sem_num = 0;
	//operacii bedut oceshecvl9tc9 nad cemaforom 0, kod operacii 1
	printf("razblokirovka processa, zapushennogo ranee\n");
	//Vipoln9em operaciy nad semaforom
	if(semop(semid, &mybuf, 1) < 0) {
		printf("ne ydaloc' get operaci nad cemaformom\n");
		exit(-1);
	}
	printf("zna4enie cemafora setyp v edinicu\n");
	return 0;
}
