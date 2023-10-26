#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#include <stdio.h>

void main()
{
    FILE* fp = fopen("data.txt", "r"); 
    char buffer[MAX] = { 0, };

    fread(buffer, 1, MAX, fp);
    printf("%s", buffer);

    fclose(fp);
}

