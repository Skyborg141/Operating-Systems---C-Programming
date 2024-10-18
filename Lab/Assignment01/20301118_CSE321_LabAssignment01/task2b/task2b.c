
#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputs;
    FILE *outputs;
    char fileContent[1000];
    inputs = fopen("inputs.txt", "r");
    fgets(fileContent, sizeof(fileContent), inputs);
    fclose(inputs);
    
    int len = strlen(fileContent);
    if (fileContent[len - 1] == '\n') {
        fileContent[len - 1] = '\0';
    }
    outputs = fopen("outputs.txt", "w");
    int i = 0, start = 0;
    while (fileContent[i] != '\0') {
        if (fileContent[i] == ' ' || fileContent[i + 1] == '\0') {
            int end = (fileContent[i] == ' ') ? i : i + 1;
            if (start < end) {
                fwrite(fileContent + start, 1, end - start, stdout);
                fprintf(outputs, "%.*s", end - start, fileContent + start);
                if (fileContent[i + 1] != '\0') {
                    printf(" ");
                    fprintf(outputs, " ");
                }
            }
            start = i + 1;
        }
        i++;
    }
    
    fclose(outputs);
    return 0;
}
