//
// Created by Agaru on 5/18/2025.
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
Node* detectCycle(Node* head) {
    if (head==nullptr || head->next==nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast!=nullptr && fast->next!=nullptr) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            break;
        }
    }
    if (slow!=fast) {
        return nullptr;
    }
    Node* pre = head;
    while (pre!=slow) {
        pre=pre->next;
        slow=slow->next;
    }
    return pre;
}
int main() {
    return 0;
}