#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int val, Node *ptr, Node *pptr)
    {
        data = val;
        next = ptr;
        prev = pptr;
    }
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node *createDBll(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i], nullptr, mover);
        mover->next = newNode;
        mover = mover->next;
    }
    return head;
}

Node *deleteHead_DLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    return head;
}

Node *deleteTail_DLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->prev->next = NULL;
    tail->prev = NULL;
    free(tail);
    return head;
}

Node* deleteKTH_node_DLL(Node* head, int k){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        if(count == k){
            break;
        }
        temp = temp->next;
    }
    if(temp->next == NULL && temp->prev == NULL){
        return NULL;
    }
    else if(temp->prev == NULL){
        return deleteHead_DLL(head);
    }
    else if(temp->next == NULL){
        return deleteTail_DLL(head);
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return head;
    }
    return head;
}

void printDBll(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "The linked list is: ";
    Node *head = createDBll(arr);
    printDBll(head);
    cout << "The linked list after deleting the head is: ";
    head = deleteHead_DLL(head);
    printDBll(head);
    cout << "The linked list after deleting the tail is: ";
    head = deleteTail_DLL(head);
    printDBll(head);
    Node* head1 = createDBll(arr);
    cout << "The linked list after deleting the 3rd node is: ";
    head1 = deleteKTH_node_DLL(head1, 3);
    printDBll(head1);

    return 0;
}