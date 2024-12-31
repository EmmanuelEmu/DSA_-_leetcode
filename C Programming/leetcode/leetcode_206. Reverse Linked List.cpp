#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *last = NULL;
    ListNode *curr = head;

    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = last;
        last = curr;
        curr = next;
    }

    return last;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *newNode = new ListNode(arr[i]);
        mover->next = newNode;
        mover = mover->next;
    }
    ListNode *ans = reverseList(head);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}