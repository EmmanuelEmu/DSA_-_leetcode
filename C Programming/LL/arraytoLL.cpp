#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int val, Node* ptr){
            data = val;
            next = ptr;
        }
        Node(int val){
            data = val;
            next = NULL;
        }
};

Node* createLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        mover->next = newNode;
        mover = mover->next;
    }
    return head;
}

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* deleteHead(Node* head){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* deleteTail(Node* head){
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
    return head;
}
int main(){

    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = createLL(arr);
    cout << head->data << endl;
    Node* temp = head;
    cout << "The linked list is: ";
    printLL(head);
    cout << endl;
    cout << "The length of the linked list is: " << lengthOfLL(head) << endl;
    head = deleteHead(head);
    cout << "The linked list after deleting the head is: ";
    printLL(head);
    cout << "The length of the linked list is: " << lengthOfLL(head) << endl;
    head = deleteTail(head);
    cout << "The linked list after deleting the tail is: ";
    printLL(head);
    return 0;
}