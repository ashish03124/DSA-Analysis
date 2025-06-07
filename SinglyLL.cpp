/*
 *Structure Of A node
 *node components-> int data (can be any type)
 *               -> Node* next(pointer to next node)
 */
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};
//Insert At Head
//head --> [10 | next] --> [20 | next] --> [30 | NULL]
//initially new_node->next==NULL, make it head new_node->next=head
// initially head is pointing to previous node make it point to the current new_node
// head --> [5 | next] --> [10 | next] --> [20 | next] --> [30 | NULL]

void insertAtHead(Node * &head, int val) {
    Node *new_node = new Node(val);
    new_node-> next = head;
    head = new_node;
}
//Insert At Tail
//create Temp node storing and traverse through whole link list until temp->next != NULL
// then Temp->next=new_node
void insertAtTail(Node* &head, int val) {
    Node* new_node = new Node(val);
    if (head==NULL) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    temp-> next = new_node;
}
//Insert At Target
// create an temp node storing head and will traverse through the ll till target
//int i=0;  while(temp!=NULL && i<target-1) { temp=temp->next; i++ }
//new_node->next = temp->next;
//temp->next=new_node;
void insertAtTarget(Node* &head, int val, int target) {
    Node* new_node = new Node(val);
    if (target==0) {
        new_node->next=head;
        head = new_node;
        return;
    }
    Node* temp = head;
    for (int i=0;temp!=NULL && i < target -1; i++) {
        temp = temp->next;
    }
    if (temp==NULL) {
        cout << "target invalid" << endl;
        delete new_node;
        return;
    }
    new_node->next=temp->next;
    temp->next=new_node;
 }

//Searching in the singly linklist

bool search(Node* head, int key) {
    Node* temp = head;
    while (temp!=NULL) {
        if (temp->data==key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
//Delete a Node
void deleteANode(Node* &head, int target) {
    if (head==NULL) return;

    //Case1: Delete head
    if (head->data==target) {
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
        return;
    }

    //Case2: Delete in middle or end
    Node* temp = head;
    while (temp->next != NULL && temp->next->data!=target) {
        temp= temp->next;
    }
    if (temp->next==NULL) {
        cout << "target is invalid" << endl;
        return;
    }
    Node* to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
}

//Delete a Node when only target is given
void deleteANode(Node* node) {
    // O(1)
    node->data = node->next->data;
    Node* temp = node->next;
    node->next = node->next->next;
    delete temp;
    // O(n)
    Node* prev = NULL;
    while (node!=NULL && node->next!=NULL) {
        node->data = node->next->data;
        prev=node;
        node = node->next;
    }
    prev->next = NULL;
    delete node;
}
// printing Linked List
void printList(Node* head) {
    while (head!=NULL) {
    cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = NULL;

    insertAtHead(head, 10);    // 10
    insertAtTail(head, 20);    // 10 -> 20
    insertAtTarget(head, 15, 1); // 10 -> 15 -> 20
    printList(head); // Output: 10 -> 15 -> 20 -> NULL
    return 0;

}
