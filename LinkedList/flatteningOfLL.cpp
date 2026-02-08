#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* child;

    Node(int x) {
        data = x;
        next = NULL;
        child = NULL;
    }
};

// Merge two sorted child-linked lists
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);
    } else {
        result = b;
        result->child = merge(a, b->child);
    }

    result->next = NULL; // important
    return result;
}

// Flatten function
Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    head->next = flattenLinkedList(head->next);
    head = merge(head, head->next);

    return head;
}

// Print flattened list using child pointer
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {
    int n;
    cout<<"Enter the number of head node:";
    cin >> n;

    Node* head = NULL;
    Node* prev = NULL;

    for (int i = 0; i < n; i++) {
        int m;
        cout<<"Enter the number of vertical node:";
        cin >> m;

        Node* verticalHead = NULL;
        Node* verticalPrev = NULL;

        for (int j = 0; j < m; j++) {
            int x;
            cout<<"Enter the value of node:";
            cin >> x;

            Node* newNode = new Node(x);

            if (verticalHead == NULL) {
                verticalHead = newNode;
            } else {
                verticalPrev->child = newNode;
            }
            verticalPrev = newNode;
        }

        if (head == NULL) {
            head = verticalHead;
        } else {
            prev->next = verticalHead;
        }
        prev = verticalHead;
    }

    head = flattenLinkedList(head);
    printList(head);

    return 0;
}
