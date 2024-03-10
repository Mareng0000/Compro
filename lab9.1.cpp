#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode* next;
};

struct studentNode* start = NULL;
struct studentNode** now = &start;

void InsNode(char n[], int a, char s, float g) {
    struct studentNode* newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (*now == NULL) {
        *now = newNode;
    }
    else {
        struct studentNode* temp = *now;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    now = &(newNode->next);
}

void DelNode() {
    if (start == NULL) {
        return;
    }

    struct studentNode* temp = start;
    struct studentNode* prev = NULL;

    while (temp != *now && temp != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (temp == start) {
        start = start->next;
    }
    else {
        prev->next = temp->next;
    }

    if (temp == *now) {
        *now = prev;
    }

    free(temp);
}

void GoNext() {
    if (*now != NULL) {
        now = &((*now)->next);
    }
}

void GoFirst() {
    now = &start;
}

void GoLast() {
    struct studentNode* temp = start;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    now = &(temp->next);
}

void ShowAll() {
    struct studentNode* temp = start;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
}

int FindNode(char n[]) {
    struct studentNode* temp = start;
    while (temp != NULL) {
        if (strcmp(temp->name, n) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

struct studentNode* NowNode() {
    return *now;
}

void EditNode(char n[], int a, char s, float g) {
    strcpy((*now)->name, n);
    (*now)->age = a;
    (*now)->sex = s;
    (*now)->gpa = g;
}

int main() {
    int menu;
    printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
    scanf("%d", &menu);
    while (menu != 0) {
        switch (menu) {
        case 1:
            {
                char name[20];
                int age;
                char sex;
                float gpa;

                printf("Enter name, age, sex, gpa: ");
                scanf("%s %d %c %f", name, &age, &sex, &gpa);
                InsNode(name, age, sex, gpa);
                printf("Data added successfully\n");
            }
            break;
        case 2:
            {
                char name[20];
                int age;
                char sex;
                float gpa;

                printf("Enter name to edit: ");
                scanf("%s", name);

                if (FindNode(name) == 1) {
                    printf("Enter new name, age, sex, gpa: ");
                    scanf("%s %d %c %f", name, &age, &sex, &gpa);
                    EditNode(name, age, sex, gpa);
                    printf("Data edited successfully\n");
                }
                else {
                    printf("Name not found\n");
                }
            }
            break;
        case 3:
            DelNode();
            break;
        case 4:
            {
                char name[20];
                printf("Enter name to find: ");
                scanf("%s", name);

                if (FindNode(name) == 1) {
                    printf("Data found:\n");
                    printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", NowNode()->name, NowNode()->age, NowNode()->sex, NowNode()->gpa);
                }
                else {
                    printf("Name not found\n");
                }
            }
            break;
        case 5:
            ShowAll();
            break;
        }

        printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
        scanf("%d", &menu);
    }

    return 0;
}
