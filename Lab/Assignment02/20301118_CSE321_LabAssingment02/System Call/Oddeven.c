//shouvik@shouvik-VirtualBox:~/task4$ gcc oddeven.c -o oddeven
//shouvik@shouvik-VirtualBox:~/task4$ ./oddeven 7 5 9 3 10 2 8
//Odd/Even Status:
//7 is odd
//5 is odd
//9 is odd
//3 is odd
//10 is even
//2 is even
//8 is even


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Odd/Even Status:\n");
    
    int i = 1;
    while (i < argc) {
        int num = atoi(argv[i]);
        
        switch (num % 2) {
            case 0:
                printf("%d is even\n", num);
                break;
            default:
                printf("%d is odd\n", num);
                break;
        }
        
        i++;
    }
    
    return 0;
}