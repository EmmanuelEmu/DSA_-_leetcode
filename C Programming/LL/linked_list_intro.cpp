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

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = new Node(v[0]);
    Node head2 = Node(v[1], nullptr);
    cout << head->data << endl;
    return 0;
}