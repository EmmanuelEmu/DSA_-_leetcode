#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val, Node *ptr)
    {
        data = val;
        next = ptr;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *createLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        mover->next = newNode;
        mover = mover->next;
    }
    return head;
}

int lengthOfLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deleteNodeIndex(Node *head, int index)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (index == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp!=NULL)
    {
        count++;
        if (count == index)
        {
            prev->next = prev->next->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


Node *deleteNodeValue(Node *head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp!=NULL)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = createLL(arr);
    cout << head->data << endl;
    Node *temp = head;
    cout << "The linked list is: ";
    printLL(head);
    cout << endl;
    head = deleteNodeValue(head, 3);
    cout << "The linked list after deletion is: ";
    printLL(head);

    return 0;
}