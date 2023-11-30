#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

void printEnviron(const char *value) {
	if (value) {
		char *var=getenv(value);

		if (var != NULL) {
			printf("%s=%s\n",value,var);
		}
		else {
			printf("Nothing\n");
		}
	}

	else {
		char **ptr;
		extern char **environ;
		
		for (ptr=environ; *ptr !=0;ptr++) {
		printf("%s \n",*ptr);
		}
	}
	exit(0);
}

void printIds() {
	printf("My Realistic User ID: %d(%s) \n",getuid(),getpwuid(getuid())->pw_name);
	printf("My Valid User ID: %d(%s) \n", geteuid(),getpwuid(geteuid())->pw_name);
}

void printGroups() {
	printf("My Realistic Group ID: %d(%s) \n", getgid(),getgrgid(getgid())->gr_name);
	printf("My Valid Group ID: %d(%s) \n",getegid(),getgrgid(getegid())->gr_name);
}

void printProcessNum() {
	printf("My Process Number: [%d] \n",getpid());
}

void printParentProcessNum() {
	printf("My Parent Process Number: [%d] \n",getppid());
}


int main(int argc, char *argv[]) {
	if (argc<2) {
		return 1;
	}

	for (int i=1;i<argc;i++) {
		if (argv[i][1]=='e') {
			if (argv[i+1]!=NULL) {
				printEnviron(argv[i+1]);
			}
			else {
				printEnviron(NULL);
			}
		}
		else if (argv[i][1]=='u') {
			printIds();
		}
		else if (argv[i][1]=='g') {
			printGroups();
		}
		else if (argv[i][1]=='i') {
			printProcessNum();
		}
		else if (argv[i][1]=='p') {
			printParentProcessNum();
		}
		else{
			printf("다시해");
		}
	}
	return 0;
}
