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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        vector<int> oddEven;
        ListNode* odd = head;
        while (odd != NULL) {
            oddEven.push_back(odd->val);
            if (odd->next == NULL)
                break;
            odd = odd->next->next;
        }
        ListNode* even = head->next;
        while (even != NULL) {
            oddEven.push_back(even->val);
            if (even->next == NULL)
                break;
            even = even->next->next;
        }
        ListNode* temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = oddEven[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};