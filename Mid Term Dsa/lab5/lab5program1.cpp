#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from beginning
void deleteBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete from end
void deleteEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    if (temp->next == NULL) {
        head = NULL;
        delete temp;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    delete temp;
}

// Forward traversal
void forwardDisplay(Node* head) {
    cout << "Forward: ";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Backward traversal
void backwardDisplay(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Backward: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

// Search
void search(Node* head, int value) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Element found at position "
                 << position << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Element not found\n";
}

// Concatenate two DLLs
Node* concatenate(Node* head1, Node* head2) {

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node* temp = head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

int main() {

    Node* head1 = NULL;
    Node* head2 = NULL;

    // Create first list
    insertEnd(head1, 10);
    insertEnd(head1, 20);
    insertEnd(head1, 30);

    cout << "First List:\n";
    forwardDisplay(head1);

    // Insert at beginning
    insertBeginning(head1, 5);

    cout << "\nAfter insertion at beginning:\n";
    forwardDisplay(head1);

    // Insert at end
    insertEnd(head1, 40);

    cout << "\nAfter insertion at end:\n";
    forwardDisplay(head1);

    // Delete beginning
    deleteBeginning(head1);

    cout << "\nAfter deletion from beginning:\n";
    forwardDisplay(head1);

    // Delete end
    deleteEnd(head1);

    cout << "\nAfter deletion from end:\n";
    forwardDisplay(head1);

    // Forward and backward
    cout << "\n";
    forwardDisplay(head1);
    backwardDisplay(head1);

    // Search
    cout << "\n";
    search(head1, 20);

    // Second list
    insertEnd(head2, 50);
    insertEnd(head2, 60);

    cout << "\nSecond List:\n";
    forwardDisplay(head2);

    // Concatenate
    head1 = concatenate(head1, head2);

    cout << "\nAfter concatenation:\n";
    forwardDisplay(head1);

    return 0;
}