#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Insert at beginning
void insertBeginning(Node*& head, int value) {

    Node* newNode = new Node(value);

    newNode->next = head;

    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int value) {

    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at given position
void insertMiddle(Node*& head, int value, int position) {

    if (head == NULL || position <= 1) {
        insertBeginning(head, value);
        return;
    }

    Node* newNode = new Node(value);

    Node* temp = head;

    for (int i = 1; i < position && temp->next != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;

    temp->next = newNode;
}

// Display linked list
void display(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node* head = NULL;

    insertBeginning(head, 10);
    insertBeginning(head, 20);

    insertEnd(head, 30);
    insertEnd(head, 40);

    insertMiddle(head, 25, 2);

    cout << "Linked List:" << endl;

    display(head);

    return 0;
}