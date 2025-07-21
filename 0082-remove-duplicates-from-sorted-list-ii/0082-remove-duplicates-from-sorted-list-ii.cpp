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
    ListNode* arrayToList(map<int, int>& uniqueValues) {
        for (auto it = uniqueValues.begin(); it != uniqueValues.end(); ++it) {
            if (it->second > 1) // Remove duplicates
            {
                uniqueValues.erase(it);
            }
        }
        if (uniqueValues.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(uniqueValues.begin()->first);
        ListNode* current = head;
        for (auto it = uniqueValues.begin(); it != uniqueValues.end(); ++it) {
            if (it != uniqueValues.begin()) {
                if (it->second == 1) // Only add unique values
                {
                    current->next = new ListNode(it->first);
                    current = current->next;
                }
            }
        }
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> uniqueValues;
        ListNode* current = head;
        while (current != nullptr) {
            uniqueValues[current->val]++;
            current = current->next;
        }
        return arrayToList(uniqueValues);
    }
};