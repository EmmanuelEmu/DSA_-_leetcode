class MyHashSet {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* head;

public:
    MyHashSet() { head = nullptr; }

    void add(int key) {
        if (contains(key))
            return; // Avoid duplicates

        ListNode* newNode = new ListNode(key);
        newNode->next = head;
        head = newNode;
    }

    void remove(int key) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            if (curr->val == key) {
                if (prev == nullptr) {
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    bool contains(int key) {
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val == key)
                return true;
            curr = curr->next;
        }
        return false;
    }
};
