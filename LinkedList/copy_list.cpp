#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    
    // Step 1: Create copy nodes and interleave them with original nodes
    Node* curr = head;
    while (curr) {
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    
    // Step 2: Set random pointers for the copy nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    // Step 3: Separate the original list and the copied list
    curr = head;
    Node* copyHead = curr->next;
    while (curr) {
        Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next) {
            copy->next = copy->next->next;
        }
        curr = curr->next;
    }
    
    return copyHead;
}

int main() {
    int n;
    cout<<"Enter the number of nodes:";
    cin >> n;
    vector<Node*> nodes(n);
    cout<<"Enter the values of nodes:";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nodes[i] = new Node(val);
        if(i > 0) nodes[i-1]->next = nodes[i];
    }
    cout<<"Enter the random index:";
    for(int i = 0; i < n; i++) {
        int randIdx;
        cin >> randIdx;
        if(randIdx != -1) {
            nodes[i]->random = nodes[randIdx];
        }
    }
    Node* copyHead = copyRandomList(nodes[0]);
    // Print the values of the copied list
    Node* curr = copyHead;
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    // Print the random pointers as indices
    vector<Node*> copyNodes;
    curr = copyHead;
    while(curr) {
        copyNodes.push_back(curr);
        curr = curr->next;
    }
    curr = copyHead;
    while(curr) {
        if(curr->random) {
            auto it = find(copyNodes.begin(), copyNodes.end(), curr->random);
            cout << (it - copyNodes.begin()) << " ";
        } else {
            cout << -1 << " ";
        }
        curr = curr->next;
    }
    cout << endl;
    return 0;
}