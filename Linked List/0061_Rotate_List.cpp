/*
  給定一鏈結串列，輸出將其循環右移k次的結果

  先將其頭尾串在一起，再從適當的地方切開
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head || NULL == head->next) return head;
        ListNode* ite = head;
        int count = 1;
        while (ite->next) {
            ite = ite->next;
            count++;
        }
        ite->next = head;
        count = count - (k % count);
        while (count--) {
            ite = ite->next;
        }
        ListNode* ans = ite->next;
        ite->next = NULL;
        return ans;
    }
};
