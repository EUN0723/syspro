#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void alarmHandler();

int main()
{
    signal(SIGALRM, alarmHandler);
    alarm(5);
    printf("Loop start \n");
    while (1)
    {
        sleep(1);
        printf("second \n");
    }
    printf("Alarm clock \n");
}

void alarmHandler(int signo)
{
    printf("Wake up\n");
    exit(0);
}

