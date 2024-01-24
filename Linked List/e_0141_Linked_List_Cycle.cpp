/*
    給定一鏈結串列，輸出該鏈結串列是否存在迴圈

    利用two pointer，一個一次走一格，一個一次走兩格，若存在迴圈則兩pointer會相遇
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if (NULL == head || NULL == head->next) return false;
        while (NULL != fast && NULL != fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
