#include <stdio.h>
#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node *next;

    Node(std::string s) : data(s), next(nullptr) {}
};

void printLinkedList(Node *head) {
    Node *curr = head;
    while (curr) {
        std::cout << curr->data;
        if(curr = curr->next) {
            std::cout << "->";
        }
    }

    std::cout << std::endl;

    return;
}

int main() {
    Node *head = new Node("A");
    head->next = new Node("B");
    head->next->next = new Node("C");

    printLinkedList(head);

    return 0;
}

