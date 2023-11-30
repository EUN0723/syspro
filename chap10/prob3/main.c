#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
    key_t key = ftok("mem.c", 65);  
    int shmid;
    char *ptr;
    char str1[] = "Do you like Linux?";
    char str2[] = "like linux?";

    shmid = shmget(key, strlen(str1) + strlen(str2) + 10, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    ptr = (char *)shmat(shmid, NULL, 0);
    if (ptr == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    printf("%s\n", str1);
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str1);

    shmdt(ptr);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
