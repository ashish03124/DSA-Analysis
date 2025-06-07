//
// Created by Agaru on 5/17/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
//input: 10->20->30->40->50
//output: 10->30->50->20->40
//10->20->30->40->50
// ^   ^   ^   ^   ^
// O   E   O   E   O
// odd = 10(head)
//even = 20(head->next)
//est = 20(head->next);
//LOOP for even
//odd->next = even->next; 10->next=20,  20->next=30; 20 = 30;
// even->next = even->next->next;   30 = 40;
// odd = 30;   // 10->30
// even = 40;  // 20->40


Node* oddEven(Node* &head) {
    Node* odd = head;
    Node* even = head->next;
    Node* est = head->next;
    while (even!=nullptr && even->next!=nullptr) {
        odd->next = even->next;
        even->next = even->next->next;
        odd= odd->next;
        even=even->next;
    }
    odd->next = est; // connecting ODD->EVEN
    return head;
}
int main() {
    return 0;
}