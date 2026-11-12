#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning(Node*& head, int value) {

    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int value) {

    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Delete from beginning
void deleteBeginning(Node*& head) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // Only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    Node* deleteNode = head;

    head = head->next;
    temp->next = head;

    delete deleteNode;
}

// Delete from end
void deleteEnd(Node*& head) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // Only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != head) {
        temp = temp->next;
    }

    Node* deleteNode = temp->next;

    temp->next = head;

    delete deleteNode;
}

// Display
void display(Node* head) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    cout << "Circular List: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// Search
void search(Node* head, int value) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    int position = 1;

    do {
        if (temp->data == value) {
            cout << "Element found at position "
                 << position << endl;
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != head);

    cout << "Element not found\n";
}

// Concatenate two circular linked lists
Node* concatenate(Node* head1, Node* head2) {

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node* last1 = head1;
    Node* last2 = head2;

    while (last1->next != head1) {
        last1 = last1->next;
    }

    while (last2->next != head2) {
        last2 = last2->next;
    }

    last1->next = head2;
    last2->next = head1;

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
    display(head1);

    // Insert beginning
    insertBeginning(head1, 5);

    cout << "\nAfter insertion at beginning:\n";
    display(head1);

    // Insert end
    insertEnd(head1, 40);

    cout << "\nAfter insertion at end:\n";
    display(head1);

    // Delete beginning
    deleteBeginning(head1);

    cout << "\nAfter deletion from beginning:\n";
    display(head1);

    // Delete end
    deleteEnd(head1);

    cout << "\nAfter deletion from end:\n";
    display(head1);

    // Search
    cout << "\n";
    search(head1, 20);

    // Second circular list
    insertEnd(head2, 50);
    insertEnd(head2, 60);

    cout << "\nSecond List:\n";
    display(head2);

    // Concatenate
    head1 = concatenate(head1, head2);

    cout << "\nAfter concatenation:\n";
    display(head1);

    return 0;
}