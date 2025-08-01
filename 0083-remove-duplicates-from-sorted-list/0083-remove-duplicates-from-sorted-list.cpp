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
    ListNode* deleteDuplicates(ListNode* head) {

        map<int, int> mp;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            if (mp.find(temp->val) != mp.end()) {
                prev->next = temp->next;
                temp = temp->next;
            } else {
                mp[temp->val] = 1;
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};