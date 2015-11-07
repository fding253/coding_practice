/* ======================
 
 Linked Lists
 Merge Two Sorted Lists: LeetCode #21
 
 ======================= */

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    // Handle empty lists
    if (!l1 && !l2) {
        return nullptr; //both lists are empty
    } else if (!l1) {
        return l2;
    } else if (!l2) {
        return l1;
    }
    
    // set head of mergedLL
    ListNode *mergedLL;
    ListNode *currNode;
    
    if (l1->val <= l2->val) {
        mergedLL = new ListNode(l1->val);
        l1 = l1->next;
    } else {
        mergedLL = new ListNode(l2->val);
        l2 = l2->next;
    }
    
    currNode = mergedLL;
    
    // go through the two lists, adding next to mergedLL until at end of l1 and l2
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            currNode->next = l1; // add l1 node to mergedLL
            l1 = l1->next; // go to next node in l1
            currNode = currNode->next; // iterate currNode
        } else {
            currNode->next = l2; // add l2 node to mergedLL
            l2 = l2->next; // go to next node in l2
            currNode = currNode->next; // iterate currNode
        }
    }
    
    // Either l1 or l2 are merged, append rest of the other list to mergedLL
    if (!l1) {
        currNode->next = l2;
    } else if (!l2) {
        currNode->next = l1;
    }
    
    return mergedLL;
}