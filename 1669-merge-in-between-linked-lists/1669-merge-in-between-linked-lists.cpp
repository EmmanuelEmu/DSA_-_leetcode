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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *firstPointer, *secondPointer;
        ListNode* curr = list1;
        int index = 0;
        while (curr != NULL) {
            if (index == a - 1) {
                firstPointer = curr;
            }
            if (index == b + 1) {
                secondPointer = curr;
                break;
            }
            curr = curr->next;
            index++;
        }
        firstPointer->next = list2;
        curr = list2;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = secondPointer;
        return list1;
    }
};