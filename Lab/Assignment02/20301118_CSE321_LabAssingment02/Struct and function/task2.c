#include <stdio.h>

int isPerfect(int num) {
    int i = 1, sum = 0;
    while(i < num) {
        if(num % i == 0) {
            sum += i;
        }
        i++;
    }
    if (sum == num)
    	return 1;
    else
    	return 0;
}

void printPerfect(int start, int end) {
    for(; start <= end; start++) {
        if(isPerfect(start)) {
            printf("output: %d\n", start);
        }
    }
}

int main() {
    int start, end;
    printf("input: ");
    scanf("%d%d", &start, &end);
    printPerfect(start, end);
    return 0;
}
