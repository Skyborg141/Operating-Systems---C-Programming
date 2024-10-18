//gcc task4.c -o output
//shouvik@shouvik-VirtualBox:~/task4$ ./output 2 3 5 7 8 9 10
//Sorted Array in Descending Order:
//10 9 8 7 5 3 2 
//Odd/Even Status:
//2 is even
//3 is odd
//5 is odd
7 is odd
//8 is even
//9 is odd
//10 is even



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid = fork();
    if (pid < 0) {
        printf("Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // array sorting
        char *args[argc];
        args[0] = "./sort";
        
        int i = 1;
        while (i < argc) {
            args[i] = argv[i];
            i++;
        }
        args[argc] = NULL;
        execv(args[0], args);
    } else {
        // Odd even
        wait(NULL); 
        char *args[argc];
        args[0] = "./oddeven";
        
        int i = 1;
        do {
            args[i] = argv[i];
            i++;
        } while (i < argc);
        
        args[argc] = NULL;
        execv(args[0], args);
    }
    return 0;
}
