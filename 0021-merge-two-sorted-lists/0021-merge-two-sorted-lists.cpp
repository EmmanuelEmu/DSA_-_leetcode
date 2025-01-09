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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        vector<int> list;
        while (temp1) {
            list.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while (temp2) {
            list.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(list.begin(), list.end());
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for (auto it : list) {
            temp->next = new ListNode(it);
            temp = temp->next;
        }
        return dummyNode->next;
    }
};