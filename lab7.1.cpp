#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode* next;
};

class LinkedList {
protected:
    studentNode* start;
    studentNode** now;

public:
    LinkedList() {
        start = nullptr;
        now = &start;
    }

    ~LinkedList() {
        studentNode* current = start;
        while (current != nullptr) {
            studentNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        studentNode* newNode = new studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = nullptr;

        if (*now == nullptr) {
            *now = newNode;
        }
        else {
            studentNode* temp = *now;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        now = &(newNode->next);
    }//end funtion

    void DelNode() {
        if (start == nullptr) {
            return;
        }

        studentNode* temp = start;
        studentNode* prev = nullptr;

        while (temp != *now && temp != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
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

        delete temp;
    }//end funtion

    void GoNext() {
        if (*now != nullptr) {
            now = &((*now)->next);
        }
    }//end funtion

    virtual void ShowNode() {
        if (*now != nullptr) {
            printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
        }
    }//end funtion
};//end class

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = &start;
    }

    void ShowNode() override {
        studentNode* temp = start;
        while (temp != nullptr) {
            printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }
    }
};//end class

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList* listC = nullptr;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}
