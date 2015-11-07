/* =================
   LeetCode problem:
   Swap Nodes in Pairs
   =================
*/

#include <stdio.h>
#include <iostream>

using namespace std;

// Linked List Definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode *head) {
    if(head==nullptr || head->next==nullptr) return head;

    ListNode *curr = head;
    ListNode *fwd = head->next;
    ListNode *tmp;
    head = head->next;

    while (curr!=nullptr || fwd!=nullptr) {
        if(fwd->next != nullptr && fwd->next->next != nullptr) {
            tmp = fwd->next;
            fwd->next = curr;
            curr->next = tmp->next;

            curr = tmp;
            fwd = tmp->next;
        }
        else {
            curr->next = fwd->next;
            fwd->next = curr;
            break;
        }

    }

    return head;
}

void printLL(ListNode *head) {
    while(head!=nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
    return;
}



int main() {
    ListNode *list = new ListNode(1);
    ListNode *newNode = new ListNode(2);
    list->next = newNode;

    newNode = new ListNode(3);
    list->next->next = newNode;

    newNode = new ListNode(4);
    list->next->next->next = newNode;
    
    
    cout << "Original list: ";
    printLL(list);

    list = swapPairs(list);

    cout << "Swapped list: ";
    printLL(list);

    return 0;
}
