class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return nullptr;

        while (true) {

            // Convert linked list to array
            vector<int> vals;
            ListNode* curr = head;
            while (curr != NULL) {
                vals.push_back(curr->val);
                curr = curr->next;
            }

            int n = vals.size();
            if (n == 0) return nullptr;

            // prefix sum
            vector<long long> prefix(n, 0);
            prefix[0] = vals[0];
            for (int i = 1; i < n; i++)
                prefix[i] = prefix[i - 1] + vals[i];

            int start = -1, end = -1, best = 0;

            // Check prefix[i] == 0 → window (0..i)
            for (int i = 0; i < n; i++) {
                if (prefix[i] == 0) {
                    int win = i + 1;
                    if (win > best) {
                        best = win;
                        start = 0;
                        end = i;
                    }
                }
            }

            // Check all (j..i)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                    long long sum = prefix[i] - (j > 0 ? prefix[j - 1] : 0);
                    if (sum == 0) {
                        int win = i - j + 1;
                        if (win > best) {
                            best = win;
                            start = j;
                            end = i;
                        }
                    }
                }
            }

            // If nothing found → break
            if (best == 0)
                break;

            // Rebuild list without (start..end)
            ListNode* dummy = new ListNode(0);
            ListNode* newNode = dummy;

            for (int i = 0; i < n; i++) {
                if (i < start || i > end) {
                    newNode->next = new ListNode(vals[i]);
                    newNode = newNode->next;
                }
            }

            head = dummy->next;
        }

        return head;
    }
};
