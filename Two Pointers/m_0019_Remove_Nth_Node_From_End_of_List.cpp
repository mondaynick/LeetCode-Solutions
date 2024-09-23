/*
  給定一鏈結串列及整數n，將鏈結串列的倒數第n個節點刪掉後並回傳

  欲取得倒數第k個節點的前面，先讓快指標走k步，若快指標已走完，代表倒數第k個等於第一個，直接回傳head->next，
  否則再讓快慢指標同時前進，直到fast->next為NULL，讓slow->next等於slow->next->next，回傳head
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        while (n--) fast = fast->next;

        if (!fast) return head->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
