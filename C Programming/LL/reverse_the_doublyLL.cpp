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

Node *insertionHead_DLL(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

Node *insertionTail_DLL(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node *insertionToKTHNode_DLL(Node *head, int data, int k)
{
    if (k == 1)
    {
        return insertionHead_DLL(head, data);
    }
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    Node *back = temp->prev;
    back->next = newNode;
    newNode->prev = back;
    newNode->next = temp;
    temp->prev = newNode;
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

Node *reverse_DLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *last = NULL;
    while (temp != NULL)
    {
        last = temp->prev;
        temp->prev = temp->next;
        temp->next = last;
        // last = temp;
        temp = temp->prev;
    }
    return last->prev;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "The linked list is: ";
    Node *head = createDBll(arr);
    printDBll(head);
    cout << "The linked list after inserting at head is: ";
    head = insertionHead_DLL(head, 0);
    printDBll(head);
    cout << "The linked list after inserting at tail is: ";
    head = insertionTail_DLL(head, 6);
    printDBll(head);
    cout << "The linked list after inserting at 3rd node is: ";
    head = insertionToKTHNode_DLL(head, 10, 3);
    printDBll(head);
    cout << "The linked list after reversing is: ";
    head = reverse_DLL(head);
    printDBll(head);
    return 0;
}