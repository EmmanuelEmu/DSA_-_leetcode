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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while (temp1 || temp2) {
            int sum = carry;
            if (temp1) {
                sum += temp1->val;
            }
            if (temp2) {
                sum += temp2->val;
            }
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            if (temp1) {
                temp1 = temp1->next;
            }
            if (temp2) {
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (carry) {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
        return dummy->next;
    }
};
