#include <stdio.h>
#include <string.h>

int main(){
    char mail[100];
    printf("Enter Mail Address: ");
    scanf("%s", mail);

    int indexofat = -1;
    int maillength = strlen(mail);
    for (int i = 0; i < maillength; ++i) {
        if (mail[i] == '@') {
            indexofat = i;
            break; // Stop the loop once '@' is found
        }
    }

    char domain[50] = "";
    if (indexofat > 0) {
        int j = 0;
        for (int i = indexofat + 1; i < maillength; ++i) {
            domain[j++] = mail[i];
        }
        domain[j] = '\0';
    }

    char old_domain[] = "kaaj.com";
    char new_domain[] = "sheba.xyz";
    if (strcmp(domain, new_domain) == 0) {
        printf("Email address is okay");
    } else if (strcmp(domain, old_domain) == 0) {
        printf("Email address is outdated");
    }

    return 0;
}