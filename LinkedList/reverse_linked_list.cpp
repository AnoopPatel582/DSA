#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

// O(n2) appraoch
// ListNode* reverseList(ListNode* head) {
//     ListNode* reverse_head=NULL;
//     while(head!=NULL){
//         ListNode* temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         ListNode* tail;
//         tail=temp;
//         temp=NULL;
//         if(reverse_head==NULL){
//             reverse_head=tail;
//         }else{
//             ListNode* reverse_temp=reverse_head;
//             while(reverse_temp!=NULL){
//                 reverse_temp=reverse_temp->next;
//             }
//             reverse_temp=tail;
//         }
//     }
//     return reverse_head;
// }

// optimal approach time complexity O(n)
//  ListNode* reverseList(ListNode* head) {
//      ListNode* prev=NULL;
//      ListNode* curr=head;
//      while(curr!=NULL){
//          ListNode* next=curr->next;
//          curr->next=prev;
//          prev=curr;
//          curr=next;
//      }
//      return prev;
//  }

// recursive method
ListNode *reverseList(ListNode *head)
{

    if (head == NULL || head->next == NULL)
        return head;
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    ListNode *head = NULL;
    int val;
    while (true)
    {
        cout << "Enter the value of linked list:";
        cin >> val;
        if (val == -1)
            break;
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }
    cout << "The Linked List: ";
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    ListNode *reverse_head = reverseList(head);
    cout << "\nThe Reverse Linked List: ";
    ListNode *rev_temp = reverse_head;
    while (rev_temp != NULL)
    {
        cout << rev_temp->val << " ";
        rev_temp = rev_temp->next;
    }
    return 0;
}
