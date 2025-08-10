/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& vec) {
        int n = vec.size();
        vector<int> result(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= vec[i]) {
                st.pop();
            }
            if (st.empty()) {
                result[i] = -1;
            } else {
                result[i] = st.top();
            }
            st.push(vec[i]);
        }
        return result;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next)
            return head;

        // store values
        vector<int> vec;
        ListNode* temp = head;
        while (temp) {
            vec.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> result = nextGreaterElement(vec);

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        temp = head;
        int idx = 0;

        while (temp) {
            if (result[idx] !=
                -1) {
                prev->next = temp->next;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
            idx++;
        }

        return dummy.next;
    }
};