#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

char savedText[MAX_LINES][MAX_LINE_LENGTH];
int totalLines = 0;

void readAndSaveText(FILE *file) {
    char ch;
    int line = 0;
    int col = 0;

    while (1) {
        if (fread(&ch, 1, 1, file) != 1) {
            break;
        }

        if (ch == '\n') {
            savedText[line][col] = '\0';
            line++;
            col = 0;
        } else {
            savedText[line][col] = ch;
            col++;
        }
    }
    totalLines = line;
}

void printLines(char *lineNumbers) {
    char *token = strtok(lineNumbers, ",");
    
    while (token != NULL) {
        int start, end;
        if (sscanf(token, "%d-%d", &start, &end) == 2) {
            if (start >= 1 && end <= totalLines && start <= end) {
                for (int i = start; i <= end; i++) {
                    printf("%s\n", savedText[i - 1]);
                }
            } else {
                printf("Invalid line range: %d-%d\n", start, end);
            }
        } else {
            int lineNumber;
            if (sscanf(token, "%d", &lineNumber) == 1) {
                if (lineNumber >= 1 && lineNumber <= totalLines) {
                    printf("%s\n", savedText[lineNumber - 1]);
                } else {
                    printf("Invalid line number: %d\n", lineNumber);
                }
            } else {
                printf("Invalid input: %s\n", token);
            }
        }
        token = strtok(NULL, ",");
    }
}

int main(int argc, char *argv[]) {
    char filename[] = "test.txt";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    readAndSaveText(file);

    fclose(file);

    int lineNumber;
    printf("File read success\n");
    printf("Total Line : %d\n", totalLines);
    printf("You can choose 1 ~ %d Line\n", totalLines);
    printf("Pls 'Enter' the line to select : ");

    char input[100];
    scanf("%s", input);

    printLines(input);

    return 0;
}

