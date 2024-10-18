#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int a, b, c;
    int total_processes = 1;
    
    a = fork();
    if (a == 0) {
        pid_t child_pid = getpid();
        if (child_pid % 2 != 0) {
            fork();
        }
    } else {
        b = fork();
        if (b == 0) {
            pid_t child_pid = getpid();
            if (child_pid % 2 != 0) {
                fork();
            }
        } else {
            c = fork();
            if (c == 0) {
                pid_t child_pid = getpid();
                if (child_pid % 2 != 0) {
                    fork();
                }
            } else {
                wait(NULL);
                total_processes = 1 + a + b + c;
                printf("Total processes created: %d\n", total_processes);
            }
        }
    }

    return 0;
}