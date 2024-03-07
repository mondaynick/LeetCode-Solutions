/*
  給定一鏈結串列，回傳其右半邊，若中間有兩個則取最右邊的回傳

  利用快慢指標，快指標一次移動兩個，慢指標一次移動一格，當快指標遍歷完後，慢指標必定在鏈結串列中間，回傳慢指標
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
