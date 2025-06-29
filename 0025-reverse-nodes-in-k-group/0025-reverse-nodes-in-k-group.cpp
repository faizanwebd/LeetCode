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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        while (true) {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* node = groupStart;
            int count = 0;
            while (node && count < k) {
                node = node->next;
                count++;
            }
            if (count < k) break;
            ListNode* prev = node;
            node = groupStart;
            for (int i = 0; i < k; ++i) {
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;
        }
        return dummy.next;
    }
};
