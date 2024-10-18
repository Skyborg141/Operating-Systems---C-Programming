//shouvik@shouvik-VirtualBox:~/task4$ gcc sort.c -o sort
//shouvik@shouvik-VirtualBox:~/task4$ ./sort 7 5 9 3 10 2 8
//Sorted Array in Descending Order:
//10 9 8 7 5 3 2



#include <stdio.h>
#include <stdlib.h>

int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main(int argc, char *argv[]) {
    int size = argc - 1;
    int *numbers = (int *)malloc(size * sizeof(int));
    int i = 0;
    
    while (i < size) {
        numbers[i] = atoi(argv[i + 1]);
        i++;
    }
    
    qsort(numbers, size, sizeof(int), compare_desc);
    
    printf("Sorted Array in Descending Order:\n");
    
    i = 0;
    while (i < size) {
        printf("%d ", numbers[i]);
        i++;
    }
    
    printf("\n");
    return 0;
}