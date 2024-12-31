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

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int count = 0;
    ListNode *lb = head;
    ListNode *rb = head;
    while (lb->next)
    {
        count++;
        if (count == left)
        {
            break;
        }
        lb = lb->next;
    }
    count = 0;
    while (rb->next)
    {
        count++;
        if (count == right)
        {
            break;
        }
        rb = rb->next;
    }
    ListNode *temp = lb;
    stack<int> st;
    while (temp != rb)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    st.push(rb->val);
    while (!st.empty())
    {
        lb->val = st.top();
        st.pop();
        lb = lb->next;
    }
    return head;
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
    int left = 2, right = 4;
    ListNode *ans = reverseBetween(head, left, right);
    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}