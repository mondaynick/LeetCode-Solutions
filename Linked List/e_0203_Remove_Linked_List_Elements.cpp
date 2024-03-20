/*
  給定一鏈結串列及val，將鏈結串列所有節點值等於val的節點刪掉後回傳

  利用鏈結串列之特性
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *res = new ListNode(0), *ite = res;
        if (!head) return nullptr;
        res->next = head;

        while (ite->next) {
            if (ite->next->val == val) {
                ListNode* temp = ite->next->next;
                delete ite->next;
                ite->next = temp;
            } else {
                ite = ite->next;
            }
        }

        return res->next;
    }
};
