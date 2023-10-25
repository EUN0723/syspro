#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_NUMBER_OPTION "-n"

void printFile(FILE *fp, int printLineNumber) {
    int c;
    int lineNumber = 1;
    int isFirstCharOnLine = 1;

    while ((c = getc(fp)) != EOF) {
        if (isFirstCharOnLine && printLineNumber) {
            printf("%6d  ", lineNumber++);
            isFirstCharOnLine = 0;
        }
        putc(c, stdout);

        if (c == '\n') {
            isFirstCharOnLine = 1;
        }
    }
}

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-n] file1 file2 file3 ...\n", argv[0]);
        return 1;
    }

    int printLineNumber = 0;

    if (argc > 2 && strcmp(argv[1], LINE_NUMBER_OPTION) == 0) {
        printLineNumber = 1;
    }

    for (i = (printLineNumber ? 2 : 1); i < argc; i++) {
        FILE *fp;

        if ((fp = fopen(argv[i], "r")) == NULL) {
            perror("Error opening file");
            return 2;
        }

        if (argc > 3) {
            printf("==> %s <==\n", argv[i]);
        }

        printFile(fp, printLineNumber);

        fclose(fp);
    }

    return 0;
}

