#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char* argv[]) {
    struct student rec;
    FILE *fp1, *fp2;

    if (argc != 3) {
        fprintf(stderr, "How to use : %s SourceFileName DestinationFileName\n", argv[0]);
        return 1;
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error Open Source File\n");
        return 2;
    }

    if ((fp2 = fopen(argv[2], "a")) == NULL) { 
        fprintf(stderr, "Error Open Destination File\n");
        fclose(fp1);
        return 2;
    }

    while (fscanf(fp1, "%d %s %hd", &rec.id, rec.name, &rec.score) == 3) {
        fprintf(fp2, "%d %s %d\n", rec.id, rec.name, rec.score); 
    }

    printf("File appended successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}

