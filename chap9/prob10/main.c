#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024

void run_command(char *cmd, int background) {
    char *token;
    char *args[MAX_INPUT_SIZE];
    int i = 0;

    token = strtok(cmd, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("Execution failed");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        if (!background) {
            waitpid(pid, NULL, 0);
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("[my_shell] ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        
        int background = 0;
        if (input[strlen(input) - 1] == '&') {
            background = 1;
            input[strlen(input) - 1] = '\0';
        }

        run_command(input, background);
    }

    return 0;
}

