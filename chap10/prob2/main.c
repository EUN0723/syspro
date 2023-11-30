#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    struct student* next;
};

void printReverse(struct student* head, int* count) {
    if (head == NULL) {
        return;
    }
    (*count)++;
    printReverse(head->next, count);
    printf("Student ID: %d, Name: %s\n", head->id, head->name);
}

int main() {
    int id, count = 0;
    char name[20];
    struct student *p, *head = NULL;

    printf("Please enter your student number and name\n");

    while (scanf("%d %s", &id, name) == 2) {
        p = (struct student *)malloc(sizeof(struct student));
        if (p == NULL) {
            perror("malloc");
            exit(1);
        }
        p->id = id;
        strcpy(p->name, name);
        p->next = head;
        head = p;
    }

    printf("Student Information (reverse)\n");
    printReverse(head, &count);
    printf("There are %d total of a student\n", count);


    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }

    return 0;
}

