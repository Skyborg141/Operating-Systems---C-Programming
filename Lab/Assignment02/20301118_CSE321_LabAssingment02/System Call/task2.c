#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_child = fork();
    
    if (pid_child < 0) {
        perror("Error in fork");
        return 1;
    }

    if (pid_child > 0) {
        wait(NULL);
        printf("I am parent\n");
    } else {
        pid_t pid_grandchild = fork();
        
        if (pid_grandchild < 0) {
            perror("Error in fork");
            return 1;
        }
        
        if (pid_grandchild > 0) {
            wait(NULL);
            printf("I am child\n");
        } else {
            printf("I am grandchild\n");
        }
    }
    
    return 0;
}
