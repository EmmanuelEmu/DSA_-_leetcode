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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head;
        ListNode* nextPair = head->next;

        while (current != nullptr && nextPair != nullptr) {
            swap(current->val, nextPair->val);
            current = current->next->next;
            nextPair = current ? current->next : nullptr;
        }

        return head;
    }
};