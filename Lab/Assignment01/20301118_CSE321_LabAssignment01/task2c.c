#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char password[100];
    printf("Enter Your Password: ");
    scanf("%s", password);

    bool hasLowercase = false;
    bool hasUppercase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false; 

    for(int idx = 0; idx < strlen(password); idx++){
        int asciiVal = password[idx];

        if(asciiVal >= 'a' && asciiVal <= 'z'){
            hasLowercase = true;
        }
        else if(asciiVal >= 'A' && asciiVal <= 'Z'){
            hasUppercase = true;
        }
        else if(asciiVal >= '0' && asciiVal <= '9'){
            hasDigit = true;
        }
        else if(asciiVal == '!' || asciiVal == '$' || asciiVal == '#' || asciiVal == '@'){
            // !, $, #, @
            hasSpecialChar = true;
        }
    }

    if(!hasLowercase){
        printf("Lowercase character missing\n");
    }
    if(!hasUppercase){
        printf("Uppercase character missing\n");
    }
    if(!hasDigit){
        printf("Digit missing\n");
    }
    if(!hasSpecialChar){
        printf("Special character missing\n");
    } 

    if(hasLowercase && hasUppercase && hasDigit && hasSpecialChar){
        printf("OK\n");
    }

    return 0;
}
