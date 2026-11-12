#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void checkLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow == fast) {

        cout << "Loop Exists" << endl;

        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow/fast is starting point of loop
        fast = fast->next;

        int cnt = 1;

        while (slow != fast) {
            fast = fast->next;
            cnt++;
        }

        cout << "No. of Elements in the loop are: "
             << cnt << endl;
    }
    else {
        cout << "No Loop Exists" << endl;
    }
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    // Creating loop
    head->next->next->next->next->next = head->next;

    checkLoop(head);

    return 0;
}