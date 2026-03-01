class Solution {
public:
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;   // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;

        // push the head of each non-empty list
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
