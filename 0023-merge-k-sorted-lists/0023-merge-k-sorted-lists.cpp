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
    ListNode* arrayToLinkedList(vector<int>& arr) {
        if (arr.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;
        for (int i = 1; i < arr.size(); i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> mergedLists;
        for (auto& list : lists) {
            while (list != nullptr) {
                mergedLists.push_back(list->val);
                list = list->next;
            }
        }
        sort(mergedLists.begin(), mergedLists.end());
        ListNode* head = arrayToLinkedList(mergedLists);
        return head;
    }
};