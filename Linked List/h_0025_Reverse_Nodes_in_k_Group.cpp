/*
  給定依戀結串列和整數k，將每k個節點做反向，不夠k個則保持原樣

  利用反轉鏈結串列和遞迴
 */

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
    ListNode* rev(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = start;
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode *start = head, *end = head;

        for (int i = 0 ; i < k ; i++) {
            if (end == nullptr) return head;
            end = end->next;
        }
        ListNode* newHead = rev(start, end);
        head->next = reverseKGroup(end, k);
        return newHead;
    }
};
