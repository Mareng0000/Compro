#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

struct studentNode *AddNode(struct studentNode **start, const char *name, int age, char sex, float gpa) {
  struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));

  if (!newNode) {
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }

  strcpy(newNode->name, name);
  newNode->age = age;
  newNode->sex = sex;
  newNode->gpa = gpa;
  newNode->next = NULL;

  if (*start == NULL) {
    newNode->back = NULL;
    *start = newNode;
  } else {
    struct studentNode *current = *start;

    while (current->next != NULL) {
      current = current->next;
    }

    current->next = newNode;
    newNode->back = current;
  }

  return newNode;
}//end funtion

void InsertNode(struct studentNode *current, const char *name, int age, char sex, float gpa) {
  if (current == NULL) {
    fprintf(stderr, "Invalid insertion point\n");
    return;
  }

  struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));

  if (!newNode) {
    fprintf(stderr, "Memory allocation error\n");
    return;
  }

  strcpy(newNode->name, name);
  newNode->age = age;
  newNode->sex = sex;
  newNode->gpa = gpa;

  newNode->next = current;
  newNode->back = current->back;

  if (current->back != NULL) {
    current->back->next = newNode;
  }

  current->back = newNode;
}//end funtion

void DelNode(struct studentNode **current) {
  if (*current == NULL) {
    fprintf(stderr, "Invalid deletion point\n");
    return;
  }

  struct studentNode *temp = *current;

  if (temp->back != NULL) {
    temp->back->next = temp->next;
  }

  if (temp->next != NULL) {
    temp->next->back = temp->back;
    *current = temp->next;
  } else {
    *current = temp->back;
  }

  free(temp);
}//end funtion

void GoBack(struct studentNode **current) {
  if (*current != NULL && (*current)->back != NULL) {
    *current = (*current)->back;
  }
}//end funtion

void ShowAll(struct studentNode *walk) {
  while (walk != NULL) {
    printf("%s ", walk->name);
    walk = walk->next;
  }
  printf("\n");
}//end funtion

int main() {
  struct studentNode *start, *now;
  start = NULL;

  now = AddNode(&start, "one", 6, 'M', 3.11);
  ShowAll(start);

  now = AddNode(&start, "two", 8, 'F', 3.22);
  ShowAll(start);

  InsertNode(now, "three", 10, 'M', 3.33);
  ShowAll(start);

  InsertNode(now, "four", 12, 'F', 3.44);
  ShowAll(start);

  GoBack(&now);

  DelNode(&now);
  ShowAll(start);

  DelNode(&now);
  ShowAll(start);

  DelNode(&now);
  ShowAll(start);

  return 0;
}
