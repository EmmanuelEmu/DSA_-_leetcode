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
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while (cnt < k-1) {
            temp1 = temp1->next;
            cnt++;
        }
        cnt = 0;
        while (cnt < n - k) {
            temp2 = temp2->next;
            cnt++;
        }
        swap(temp1->val, temp2->val);
        return head;
    }
};