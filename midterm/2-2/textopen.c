#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	FILE * fp;
	char str[100], ans[100]
		int num = 0, pass = 0;
	gets(ans);

	fp = fopen("data.txt", "r");
	if(fp == NULL) {
		return -1;
	}

	while(!feof(fp)) {
		fgets(str, 100, fp);
		if(strstr(str, ans) !=NULL) {
		}
	}
	if(pass == 0) 
		fclose(fp);
	return 0;
}
