#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int p;
    int c;
    Node* next;

    Node(int p, int c) {
        this->p = p;
        this->c = c;
        this->next = NULL;
    }
};

Node* multiply(Node* poly1, Node* poly2) {

    map<int, int> mpp;

    for (Node* temp1 = poly1; temp1 != NULL; temp1 = temp1->next) {

        for (Node* temp2 = poly2; temp2 != NULL; temp2 = temp2->next) {

            int power = temp1->p + temp2->p;
            int coeff = temp1->c * temp2->c;

            mpp[power] += coeff;
        }
    }

    Node* ans = NULL;
    Node* tail = NULL;

    for (auto it : mpp) {

        Node* nw = new Node(it.first, it.second);

        if (ans == NULL) {
            ans = nw;
            tail = nw;
        }
        else {
            tail->next = nw;
            tail = nw;
        }
    }

    return ans;
}

void print(Node* head) {

    Node* nd = head;

    while (nd->next != NULL) {

        cout << nd->c << "x^" << nd->p << " + ";

        nd = nd->next;
    }

    cout << nd->c << "x^" << nd->p << endl;
}

int main() {

    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // 3x^2 + 2x + 1
    poly1 = new Node(0, 1);
    poly1->next = new Node(1, 2);
    poly1->next->next = new Node(2, 3);

    // 2x^2 + 3x + 4
    poly2 = new Node(0, 4);
    poly2->next = new Node(1, 3);
    poly2->next->next = new Node(2, 2);

    Node* ans = multiply(poly1, poly2);

    cout << "Polynomial 1: ";
    print(poly1);

    cout << "Polynomial 2: ";
    print(poly2);

    cout << "Result: ";
    print(ans);

    return 0;
}