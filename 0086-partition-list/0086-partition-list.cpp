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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;
        while (temp != NULL) {
            if (temp->val < x) {
                less->next = temp;
                less = less->next;
            } else {
                greater->next = temp;
                greater = greater->next;
            }
            temp = temp->next;
        }
        less->next = greaterHead->next; // Connect less list to greater list
        greater->next = NULL;           // End the greater list
        ListNode* result =
            lessHead->next; // The head of the new partitioned list
        delete lessHead;    // Clean up the dummy head
        delete greaterHead; // Clean up the dummy head
        return result;
    }
};