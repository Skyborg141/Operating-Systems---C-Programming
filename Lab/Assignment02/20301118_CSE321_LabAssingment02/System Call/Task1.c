//shouvik@shouvik-VirtualBox:~$ cd task1
//shouvik@shouvik-VirtualBox:~/task1$ touch task1.c
//shouvik@shouvik-VirtualBox:~/task1$ gedit task1.c
//shouvik@shouvik-VirtualBox:~/task1$ gcc task1.c -o task1
//shouvik@shouvik-VirtualBox:~/task1$ ./task1 string.txt
//Enter strings (type '-1' to finish):
//Input: Hello World
//Input: This is a random string
//Input: -1
//Data saved successfully to string.txt. //Code from terminal



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect usage! Example: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *filePtr = fopen(argv[1], "w");
    if (!filePtr) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char input[MAX_LENGTH];
    printf("Enter strings (type '-1' to finish):\n");
    
    while (1) {
        printf("Input: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove newline
        
        if (!strcmp(input, "-1"))  // Stop if input is "-1"
            break;

        fprintf(filePtr, "%s\n", input);  // Write to file
    }

    fclose(filePtr);
    printf("Data saved successfully to %s.\n", argv[1]);
    
    return 0;
}





