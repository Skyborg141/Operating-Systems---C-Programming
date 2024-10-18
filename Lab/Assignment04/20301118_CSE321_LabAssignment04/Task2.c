#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#define MaxCrops 5 
#define warehouseSize 5 
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'};   
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; 
pthread_mutex_t mutex;

void *Farmer(void *farmer_number)
{
    int farmer_num = *(int *)farmer_number;

    while (1)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

       
        printf("Farmer %d: Insert crops %c at %d\n", farmer_num, crops[farmer_num - 1], in);
        warehouse[in] = crops[farmer_num - 1];
        in = (in + 1) % warehouseSize;
        printf("Farmer%d: %c%c%c%c%c\n", farmer_num, warehouse[0], warehouse[1], warehouse[2], warehouse[3], warehouse[4]);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *ShopOwner(void *shopowner_number)
{
    
    int shopowner_num = *(int *)shopowner_number;

    while (1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("Shop owner %d: Remove crops %c from %d\n", shopowner_num, warehouse[out], out);
        warehouse[out] = 'N';
        out = (out + 1) % warehouseSize;
        printf("ShopOwner%d: %c%c%c%c%c\n", shopowner_num, warehouse[0], warehouse[1], warehouse[2], warehouse[3], warehouse[4]);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{
        pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);
    int a[5] = {1, 2, 3, 4, 5}; 
       for (int i = 0; i < 5; i++)
    {
        pthread_create(&Far[i], NULL, Farmer, (void *)&a[i]);
        pthread_create(&Sho[i], NULL, ShopOwner, (void *)&a[i]);
    }
    sleep(10);
       pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
