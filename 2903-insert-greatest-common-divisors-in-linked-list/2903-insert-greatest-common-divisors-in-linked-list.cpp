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
    int GCD(int a, int b) {
        if (a % b == 0)
            return b;
        return GCD(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* currentFirstNumber = head;
        ListNode* currentSecondNumber = head->next;
        while (currentSecondNumber != nullptr) {
            int gcd = GCD(currentFirstNumber->val, currentSecondNumber->val);
            ListNode* newNode = new ListNode(gcd);
            currentFirstNumber->next = newNode;
            newNode->next = currentSecondNumber;
            currentFirstNumber = newNode->next;
            currentSecondNumber = currentFirstNumber->next;
        }
        return head;
    }
};