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
        vector<int> result(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= vec[i]) {
                st.pop();
            }
            if (st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top();
            }
            st.push(vec[i]);
        }
        return result;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> vec;
        while (temp != NULL) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> result = nextGreaterElement(vec);
        return result;
    }
};