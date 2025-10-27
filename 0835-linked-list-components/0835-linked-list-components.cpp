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
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int, bool> numMap;
        for (auto num : nums)
            numMap[num] = true;
        int components = 0;
        ListNode* curr = head;
        while (curr) {
            if (numMap.find(curr->val) != numMap.end()) {
                components++;
                while (curr && numMap.find(curr->val) != numMap.end())
                    curr = curr->next;
            } else {
                curr = curr->next;
            }
        }
        return components;
    }
};