#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define THREAD_COUNT 5
#define VALUES_PER_THREAD 5

void *printNumbers(void *arg) {
    int id = *((int *)arg);

    int start = id * VALUES_PER_THREAD + 1;
    int end = start + VALUES_PER_THREAD;

    while (start < end) {
        printf("Thread %d outputs %d\n", id, start);
        start++;
    }

    return NULL;
}

int main() {
    pthread_t tid[THREAD_COUNT];
    int ids[THREAD_COUNT];

    int count = 0;
    while (count < THREAD_COUNT) {
        ids[count] = count;
        pthread_create(&tid[count], NULL, printNumbers, &ids[count]);
        pthread_join(tid[count], NULL);
        count++;
    }

    return 0;
}
