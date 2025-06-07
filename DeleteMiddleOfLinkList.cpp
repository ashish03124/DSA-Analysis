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
// void deleteAtMiddle(Node* &head) {
//     Node* temp = head;
//     int count=0;
//     if (head==nullptr) {
//         return;
//     }
//     while (temp!=nullptr) {
//         count++;
//         temp=temp->next;
//     }
//     int n = count/2;
//     Node* tem = head;
//     int i=0;
//     while (tem->next!=nullptr && i< n-1) {
//         tem = tem->next;
//     }
//     Node* k = tem->next;
//     tem->next = tem->next->next;
//     delete k;
// }
//slow=next;
//fast=next->next;
void deleteAtMiddle(Node* &head) {
    Node* prev = nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast!=nullptr && fast->next!=nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next= slow->next;
    delete slow;

}
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void pushBack(Node* &head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

int main() {
    Node* head = nullptr;
    pushBack(head, 1);
    pushBack(head, 2);
    pushBack(head, 3);
    pushBack(head, 4);

    cout << "Before deletion: ";
    printList(head);

    deleteAtMiddle(head);

    cout << "After deletion: ";
    printList(head);
}