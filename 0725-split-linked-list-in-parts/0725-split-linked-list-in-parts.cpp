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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }
        int partSize = length / k;
        int extraNodes = length % k;
        vector<ListNode*> parts;
        curr = head;
        for (auto i = 0; i < k; i++) {
            ListNode* partHead = curr;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes = max(0, extraNodes - 1);
            for (auto j = 0; j < currentPartSize - 1; j++) {
                if (curr)
                    curr = curr->next;
            }
            if (curr) {
                ListNode* nextPartHead = curr->next;
                curr->next = nullptr;
                curr = nextPartHead;
            }
            parts.push_back(partHead);
        }
        return parts;
    }
};