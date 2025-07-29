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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head == NULL || head->next == nullptr) return head;
        ListNode* listSize = head;
        int count = 0;
        while (listSize != NULL) {
            count++;
            listSize = listSize->next;
        }
        if(k%count == 0) return head;
        int indexToSplit = count - k % count;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (indexToSplit--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        ListNode* newHead = curr;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = head;
        return newHead;
    }
};