#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char input[50];
    printf("Enter a String: ");
    scanf("%s", input);
    
    int length = strlen(input);
    int left = 0;
    int right = length - 1;
    bool is_palindrome = true;

    while (left < right) {
        if (input[left] != input[right]) {
            is_palindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    return 0;
}
