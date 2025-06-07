//
// Created by Agaru on 5/19/2025.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
void reverse(Node* head) {
    Node* pre = nullptr;
    Node* temp = head;
    while (temp) {
        Node* nxt = temp->next;
        temp->next=pre;
        pre = temp;
        temp = nxt;
    }
    return pre;

}
int main() {
    return 0;
}