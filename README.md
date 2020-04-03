# SoalShiftSISOP20_modul3_D07

Maisie Chiara Salsabila - 05111840000057
David Bintang - 05111840000090

## Daftar Isi
1. [Nomor 1](#1)
  	- [Nomor 1 - Pokezone](#1p)
	- [Nomor 1 - Traizone](#1t)
2. [Nomor 2](#2)
3. [Nomor 3](#3)
4. [Nomor 4](#4)
	- [Nomor 4a](#4a)
	- [Nomor 4b](#4b)
	- [Nomor 4c](#4c)


<a name="1"></a>
## 1. 
### Soal:
<a name="1p"></a>
#### Pokezone


<a name="1t"></a>
#### Traizone




<a name="2"></a>
## 2. 
### Soal:




<a name="3"></a>
## 3. 
### Soal:




<a name="4"></a>
## 4. Norland
### Soal:
Norland adalah seorang penjelajah terkenal. Pada suatu malam Norland menyusuri jalan setapak menuju ke sebuah gua dan mendapati tiga pilar yang pada setiap pilarnya ada sebuah batu berkilau yang tertancap. Batu itu berkilau di kegelapan dan setiap batunya memiliki warna yang berbeda. Norland mendapati ada sebuah teka-teki yang tertulis di setiap pilar. Untuk dapat mengambil batu mulia di suatu pilar, Ia harus memecahkan teka-teki yang ada di pilar tersebut. Norland menghampiri setiap pilar secara bergantian.
<a name="4a"></a>
#### a) Batu mulia pertama. Emerald. Batu mulia yang berwarna hijau mengkilat. Pada batu itu Ia menemukan sebuah kalimat petunjuk. Ada sebuah teka-teki yang berisi:
#### 1. Buatlah program C dengan nama "4a.c", yang berisi program untuk melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).
#### 2. Tampilkan matriks hasil perkalian tadi ke layar.
```
int mat42[4][2];
int mat25[2][5];
int status;
int (*res)[5];
pthread_t threads[10], t1, t2;
int *p;
```
Mendeklarasikan variabel secara universal

```
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
```
mengisi setiap elemen matriks 4x2

```
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
```
mengisi setiap elemen matriks 2x5

```
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
```
Template rumus perkalian matriks mxn

```
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
```
Fungsi main yang terdiri atas:
- Template shared memory untuk menyimpan suatu data dan agar data tersebut dapat digunakan disuatu kesempatan.
```
    key_t key = 12345;
    int shmid = shmget(key, sizeof(int[5][5]), IPC_CREAT | 0666);
    res = shmat(shmid, 0, 0);
```
- Print hasil perkalian
```
    printf ("Result matrix is :\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            printf ("%d ", res[i][j]);
        }
        printf ("\n");
    }
```


<a name="4b"></a>
#### b) Batu kedua adalah Amethyst. Batu mulia berwarna ungu mengkilat. Teka-tekinya adalah:
#### 1. Buatlah program C kedua dengan nama "4b.c". Program ini akan mengambil variabel hasil perkalian matriks dari program "4a.c" (program sebelumnya), dan tampilkan hasil matriks tersebut ke layar. (Catatan!: gunakan shared memory)
#### 2. Setelah ditampilkan, berikutnya untuk setiap angka dari matriks tersebut, carilah nilai penjumlahan dari n hingga 1, dan tampilkan hasilnya ke layar dengan format seperti matriks.
```
int (*res)[5];
unsigned long long hasil[4][5];
```
Deklarasi variabel secara universal

```
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
```
Fungsi sum untuk menjumlahkan setiap n value elemen sampai 1. misal n=3 maka 3+2+1.
- Shared memory
```
    key_t key = 12345;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    res = shmat(shmid, 0, 0);
```
- Looping untuk menjumlahkan value elemen
```
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
```

```
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
```
Fungsi di atas adalah fungsi main yang terdiri dari:
- Shared Memory
```
key_t key = 12345;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    res = shmat(shmid, 0, 0);
```
- Print Hasil perkalian matrix
```
 printf ("Result matrix is :\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            printf ("%d ", res[i][j]);
        }
        printf ("\n");
    }
```
- print hasil sum dan thread
```
printf ("\nHasil sum dari n sampai 1 adalah:\n");

    pthread_t tid;
	pthread_create(&tid, NULL, sum, NULL);
	pthread_join(tid,NULL);

```



<a name="4c"></a>
#### c) Batu ketiga adalah Onyx. Batu mulia berwarna hitam mengkilat. Pecahkan teka-teki berikut!
#### 1. Buatlah program C ketiga dengan nama "4c.c". Program ini tidak memiliki hubungan terhadap program yang lalu.
#### 2. Pada program ini, Norland diminta mengetahui jumlah file dan folder di direktori saat ini dengan command "ls | wc -l". Karena sudah belajar IPC, Norland mengerjakannya dengan semangat. (Catatan! : Harus menggunakan IPC Pipes)
```
int main () 
{
    int fd[2];
    pid_t p;

    int count = 0;

    if (pipe(fd)==-1) { 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 
    
    p = fork();

    if (p < 0) { 
		fprintf(stderr, "fork failed" ); 
		return 1; 
	}

    // child process
    else if (p == 0) { 
        dup2(fd[0], 0);
        close(fd[1]);
        char *wc_arg[] = {"wc", "-l", NULL};
	execvp("wc", wc_arg);
    }

    // parent process
    else {  
        dup2(fd[1], 1);
        close(fd[0]);
        char *ls_arg[] = {"ls", NULL};
        execvp("ls", ls_arg);
    }
}
```
Program di atas didapatkan dari template pada modul 3 dengan sedikit modifikasi meneysuaikan dengan permasalahan yang ada.



## Kendala
1. No 1 dan 2 di luar batas kemampuan saya hehe
2. No 3, entah kenapa zipnya di saya tidak bisa di download.
