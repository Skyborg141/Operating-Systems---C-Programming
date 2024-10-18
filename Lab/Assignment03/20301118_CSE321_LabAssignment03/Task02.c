#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>  
#include <unistd.h>
#include <ctype.h>  

struct msg {
    long int type;
    char txt[10];  
};


void remove_queue(int msgid) {
    msgctl(msgid, IPC_RMID, NULL);
}

int main() {
    key_t key;
    int msgid;
    struct msg message;

    
    key = ftok("progfile", 65);

   
    msgid = msgget(key, 0666 | IPC_CREAT);

  
    if (fork() == 0) { // Child process OTP generator
        sleep(1); // Simulate the log in sending the message first

      
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("OTP generator received workspace name from log in: %s\n", message.txt);

      
        int otp = 13055;
        snprintf(message.txt, sizeof(message.txt), "%d", otp);
        message.type = 2;

     
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("OTP sent to log in from OTP generator: %s\n", message.txt);


        message.type = 3;
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("OTP sent to mail from OTP generator: %s\n", message.txt);

     
        if (fork() == 0) { // Child process of OTP generator
            // Read OTP from the message queue
            msgrcv(msgid, &message, sizeof(message), 3, 0);
            printf("Mail received OTP from OTP generator: %s\n", message.txt);

       
            message.type = 4;
            msgsnd(msgid, &message, sizeof(message), 0);
            printf("OTP sent to log in from mail: %s\n", message.txt);

            exit(0);
        }

        wait(NULL); 
        exit(0);
    } else { // Parent process (log in)
       
        char workspace[10];
        printf("Please enter the workspace name: ");
        scanf("%s", workspace);

      
        for (int i = 0; workspace[i]; i++) {
            workspace[i] = tolower(workspace[i]);
        }

      
        if (strcmp(workspace, "cse321") != 0) {
            printf("Invalid workspace name\n");
            remove_queue(msgid); // Remove message queue
            exit(0);
        }

       
        strcpy(message.txt, workspace);
        message.type = 1;
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Workspace name sent to OTP generator from log in: %s\n", message.txt);

        wait(NULL); 

        
        msgrcv(msgid, &message, sizeof(message), 2, 0);
        printf("Log in received OTP from OTP generator: %s\n", message.txt);
        char otp_from_otp[10];  // Increased size to store larger OTP values
        strcpy(otp_from_otp, message.txt);

       
        msgrcv(msgid, &message, sizeof(message), 4, 0);
        printf("Log in received OTP from mail: %s\n", message.txt);
        char otp_from_mail[10];  // Increased size to store larger OTP values
        strcpy(otp_from_mail, message.txt);

    
        if (strcmp(otp_from_otp, otp_from_mail) == 0) {
            printf("OTP Verified\n");
        } else {
            printf("OTP Incorrect\n");
        }

        remove_queue(msgid); // Remove message queue
    }

    return 0;
}

