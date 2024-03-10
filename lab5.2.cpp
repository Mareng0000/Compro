#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void InsNode(struct studentNode **now, char *name, int age, char sex, float gpa);
void DelNode(struct studentNode **now);
void GoNext(struct studentNode ***now);
void ShowAll(struct studentNode **start);

int main() {
    struct studentNode *start = NULL;
    struct studentNode **now = &start;

    InsNode(now, "one", 6, 'M', 3.11);
    ShowAll(&start);

    InsNode(now, "two", 8, 'F', 3.22);
    ShowAll(&start);

    GoNext(&now);

    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(&start);

    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(&start);

    GoNext(&now);

    DelNode(now);
    ShowAll(&start);

    return 0;
}

void InsNode(struct studentNode **now, char *name, int age, char sex, float gpa) {
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    if (newNode == NULL) {
        printf("Failed.\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = *now;
    *now = newNode;
}//end funtion

void DelNode(struct studentNode **now) {
    if (*now == NULL) {
        printf("Successful\n");
        return;
    }
    struct studentNode *temp = *now;
    *now = (*now)->next;
    free(temp);
}//end funtion

void GoNext(struct studentNode ***now) {
    if (*now != NULL && (**now)->next != NULL) {
        *now = &((**now)->next);
    } else {
        printf("Already.\n");
    }
}//end funtion

void ShowAll(struct studentNode **walk) {
    while (*walk != NULL) {
        printf("%s ", (*walk)->name);
        walk = &((*walk)->next);
    }
    printf("\n");
}//end funtion
