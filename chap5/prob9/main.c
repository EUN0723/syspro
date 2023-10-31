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

void printReversedLines() {
    for (int i = totalLines - 1; i >= 0; i--) {
        printf("%s\n", savedText[i]);
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

    printf("Reversed Content of %s:\n", filename);
    printReversedLines();

    return 0;
}

