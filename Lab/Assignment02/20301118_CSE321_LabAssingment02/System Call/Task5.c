#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main() {
    printf("1. Parent process ID: %d\n", getpid());
    pid_t child_pid = fork();
    if (child_pid == 0) {
        printf("2. Child process ID: %d\n", getpid());
        for (int i = 0; i < 3; ++i) {
            pid_t grandchild_pid = fork();
            if (grandchild_pid == 0) {
                printf("%d. Grandchild process ID: %d\n", 3 + i, getpid());
                break; 
            }
        }
    }
    return 0;
}
