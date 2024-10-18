#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

struct shared {
    char sel[100];
    int b;
};

int main() {
    int shmid;
    int fd[2];
    struct shared *shm;

    shmid = shmget(IPC_PRIVATE, sizeof(struct shared), 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    shm = (struct shared *) shmat(shmid, NULL, 0);
    if (shm == (struct shared *) -1) {
        perror("shmat failed");
        exit(1);
    }

    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    shm->b = 1000;

    printf("Provide Your Input From Given Options:\n");
    printf("1. Type a to Add Money\n");
    printf("2. Type w to Withdraw Money\n");
    printf("3. Type c to Check Balance\n");

    fgets(shm->sel, 100, stdin);
    shm->sel[strcspn(shm->sel, "\n")] = '\0';

    printf("Your selection: %s\n", shm->sel);

    pid_t pid = fork();

    if (pid == 0) { // Child process (opr)
        if (strcmp(shm->sel, "a") == 0) {
            int amount;
            printf("Enter amount to be added:\n");
            scanf("%d", &amount);

            if (amount > 0) {
                shm->b += amount;
                printf("Balance added successfully\n");
                printf("Updated balance after addition: %d\n", shm->b);
            } else {
                printf("Adding failed, Invalid amount\n");
            }

        } else if (strcmp(shm->sel, "w") == 0) {
            int amount;
            printf("Enter amount to be withdrawn:\n");
            scanf("%d", &amount);

            if (amount > 0 && amount <= shm->b) {
                shm->b -= amount;
                printf("Balance withdrawn successfully\n");
                printf("Updated balance after withdrawal: %d\n", shm->b);
            } else {
                printf("Withdrawal failed, Invalid amount\n");
            }

        } else if (strcmp(shm->sel, "c") == 0) {
            printf("Your current balance is: %d\n", shm->b);
        } else {
            printf("Invalid selection\n");
        }

   
        write(fd[1], "Thank you for using\n", 20);
        close(fd[1]);

        shmdt(shm);
        exit(0);

    } else { 
        wait(NULL);

    
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("%s", buffer);
        close(fd[0]);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);

        exit(0);
    }
}

