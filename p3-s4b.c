#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <pthread.h>

int (*res)[5];
unsigned long long hasil[4][5];

void *sum (void *arg)
{
    key_t key = 12345;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    res = shmat(shmid, 0, 0);
    int val;
    unsigned long long temp = 0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            val = res[i][j];
            for (int k=0; k<=val; k++) {
                temp += k;
                hasil[i][j] = temp;
            }
            printf ("%llu ", hasil[i][j]);
            temp = 0;
        }
        printf ("\n");
    }
}

int main ()
{
    key_t key = 12345;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    res = shmat(shmid, 0, 0);
    
    printf ("Result matrix is :\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            printf ("%d ", res[i][j]);
        }
        printf ("\n");
    }

    printf ("\nHasil sum dari n sampai 1 adalah:\n");

    pthread_t tid;
	pthread_create(&tid, NULL, sum, NULL);
	pthread_join(tid,NULL);

    return 0;
}