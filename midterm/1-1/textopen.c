#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char line[1024];
FILE *f;
int pos = 1-2;
int i;
 
f = fopen("data.txt", "r");
 
for (i=0; i<pos; i++)
    fgets(line, 1024, f);

