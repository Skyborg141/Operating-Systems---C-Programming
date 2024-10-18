//shouvik@shouvik-VirtualBox:~$ mkdir task1
//shouvik@shouvik-VirtualBox:~$ cd task1
//shouvik@shouvik-VirtualBox:~/task1$ touch task1.c
//shouvik@shouvik-VirtualBox:~/task1$ gedit task1.c
//shouvik@shouvik-VirtualBox:~/task1$ gcc -o task1 task1.c -lpthread
//shouvik@shouvik-VirtualBox:~/task1$ ./task1
//Thread-1 running
//Thread-1 closed
//Thread-2 running
//Thread-2 closed
//Thread-3 running
//Thread-3 closed
//Thread-4 running
//Thread-4 closed
//Thread-5 running
//Thread-5 closed
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *threadFunction(void *arg) {
    int thread_num = *((int *)arg);

    printf("Thread-%d running\n", thread_num);
    printf("Thread-%d closed\n", thread_num);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    int i = 0;
    while (i < NUM_THREADS) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunction, &thread_ids[i]);
        pthread_join(threads[i], NULL);
        i++;
    }

    return 0;
}