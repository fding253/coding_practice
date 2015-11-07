/* ==========================
   Write a function that creates a linked list with random letters stored in it. The method takes in a length and letter range. It will return the head to the new list.

   Assumes all input is valid: numNodes>=1, minLetter<=maxLetter.
   ========================== */


#include <stdio.h>
#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node *next;

    Node(std::string s) : data(s), next(nullptr) {};
};

void printLinkedList(Node *head) {
    Node *curr = head;
    while (curr) {
        std::cout << curr->data;
        if( (curr = curr->next) ) {
            std::cout << "->";
        }
    }

    std::cout << std::endl;

    return;
}

Node *createRandomList(int numNodes, char minLetter, char maxLetter) {

    Node *curr = nullptr;
    Node *head = curr;
    int range;
    std::string randLetter;

    while(numNodes>0) {
        range = maxLetter - minLetter;
        randLetter = std::string(1, (char)((rand() % range) + minLetter) );
        if(curr) {
            curr->next = new Node(randLetter);
            curr = curr->next;
        } 
        else {
            curr = new Node(randLetter);
            head = curr;
        }
        numNodes--;
    }

    return head;

}

int main() {
    Node *list;

    list = createRandomList(5,'A','E');
    printLinkedList(list);

    return 0;

}
