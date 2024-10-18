#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdint.h> 
#define MAX_NAME_LENGTH 50
int calculateASCII(const char *username) {
    int sum = 0;
    for (int i = 0; username[i] != '\0'; ++i) {
        sum += (int)username[i];
    }
    return sum;
}
void *checkEquality(void *arg) {
    int *values = (int *)arg;
    if (values[0] == values[1] && values[1] == values[2]) {
        printf("Youreka\n");
    } else if (values[0] == values[1] || values[1] == values[2] || values[0] == values[2]) {
        printf("Miracle\n");
    } else {
        printf("Hasta la vista\n");
    }
    return NULL;
}
void *calculateUsernameASCII(void *arg) {
    char *username = (char *)arg;
    int asciiSum = calculateASCII(username);
    printf("Name: %s, ASCII Sum: %d\n", username, asciiSum);
    return (void *)(intptr_t)asciiSum;
}
int main() {
    pthread_t threads[4];
    int asciiValues[3];
    //char usernames[3][MAX_NAME_LENGTH] = {"Argha", "Argha", "Argha"}; //This will give output Youreka
    char usernames[3][MAX_NAME_LENGTH] = {"Shouvik", "Banerjee", "Argha"};
    for (int i = 0; i < 3; ++i) {
        pthread_create(&threads[i], NULL, calculateUsernameASCII, (void *)usernames[i]);
    }
    for (int i = 0; i < 3; ++i) {
        void *result;
        pthread_join(threads[i], &result);
        asciiValues[i] = (int)(intptr_t)result;
    }
    pthread_create(&threads[3], NULL, checkEquality, (void *)asciiValues);
    pthread_join(threads[3], NULL);
    return 0;
}