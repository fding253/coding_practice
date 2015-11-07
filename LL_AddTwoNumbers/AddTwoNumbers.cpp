/* =====================
   LeetCode problem #2:
   Add Two Numbers (Linked Lists)

   You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8

    ===================== */


// Definition for singly-linked list.
struct ListNode {     
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int digitSum;
    int carryover = 0;
    ListNode *result = new ListNode(0);
    ListNode *resCurr = result;
    
    // Handle empty lists
    if(!l1) {
        return l2;
    } else if (!l2) {
        return l1;
    }
    
    while(l1 && l2) {
        // sum up the digits plus any carryover
        digitSum = l1->val + l2->val + carryover;
        
        // Create a new node with the ones-value of the sum
        if (digitSum > 9) {
            resCurr->next = new ListNode(digitSum%10);
            carryover = 1; //two single digits added together has max of 18
        } else {
            resCurr->next = new ListNode(digitSum);
            carryover = 0;
        }
        
        // Increment things
        resCurr = resCurr->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    // Reached the end of at least one list
    while (l2) {
        // if reached end of l1, go through and add rest of l2
        digitSum = l2->val + carryover;
        resCurr->next = new ListNode(digitSum%10);
        carryover = (int) digitSum/10;
        resCurr = resCurr->next;
        l2 = l2->next;
    }
    
    while (l1) {
        // if reached end of l2, go through and add rest of l1
        digitSum = l1->val + carryover;
        resCurr->next = new ListNode(digitSum%10);
        carryover = (int) digitSum/10;
        resCurr = resCurr->next;
        l1 = l1->next;
    }
    
    // now both lists are empty...add carryover
    if(carryover>0)
        resCurr->next = new ListNode(carryover);
    
    return result->next;
}



