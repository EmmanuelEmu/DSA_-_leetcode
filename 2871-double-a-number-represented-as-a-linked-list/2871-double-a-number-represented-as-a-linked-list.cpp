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
    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = reverseList(head);
        int carry = 0;
        int digit;
        ListNode* newHead = NULL;
        while (temp != NULL) {
            digit = temp->val * 2 + carry;
            carry = digit / 10;
            digit = digit % 10;
            ListNode* newNode = new ListNode(digit);
            newNode->next = newHead;
            newHead = newNode;
            temp = temp->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = newHead;
            newHead = newNode;
        }
        return newHead;
    }
};