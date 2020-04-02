#include <stdio.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int mat42[4][2];
int mat25[2][5];
int status;
int (*res)[5];
pthread_t threads[10], t1, t2;
int *p;

void *matrix42 (void *arg)
{
    status = 0;
    mat42[0][0] = 1;
    mat42[0][1] = 1;
    mat42[1][0] = 1;
    mat42[1][1] = 1;
    mat42[2][0] = 1;
    mat42[2][1] = 1;
    mat42[3][0] = 1;
    mat42[3][1] = 1;
    status = 1;
    return 0;
}

void *matrix25 (void *arg)
{
    while (status != 1)
	{

	}
    mat25[0][0]=1;
    mat25[0][1]=1;
    mat25[0][2]=1;
    mat25[0][3]=1;
    mat25[0][4]=1;
    mat25[1][0]=1;
    mat25[1][1]=1;
    mat25[1][2]=1;
    mat25[1][3]=1;
    mat25[1][4]=1;
    status=2;
	return 0;
}

void *multiply (void *arg)
{
    while (status != 2) {}
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {  
            res[i][j] = 0;
            for (int k = 0; k < 2; k++) {  
                res[i][j] += mat42[i][k] * mat25[k][j];
            }
        }
    }
}

int main ()
{
    key_t key = 12345;
    int shmid = shmget(key, sizeof(int[5][5]), IPC_CREAT | 0666);
    res = shmat(shmid, 0, 0);
    
    printf ("Result matrix is :\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            printf ("%d ", res[i][j]);
        }
        printf ("\n");
    }
    return 0;
}