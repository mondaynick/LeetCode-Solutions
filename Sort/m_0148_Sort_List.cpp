/*
  給定一鏈結串列，回傳將其升冪排序後的鏈結串列

  利用合併排序，使用two pointer，定義兩指標slow, fast，一個一次走一格，一個一次走兩格，
  定義指標prev指向slow前一節點，當fast走到尾巴時，slow會在中間，將prev.next設為null即可將鏈結串列分割為二，
  再透過遞迴分割，最後合併得到排序好的鏈結串列
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *prev = NULL, *slow = head, *fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        ListNode* ans = new ListNode(0);
        ListNode* ite = ans;
        while (left && right) {
            if (left->val < right->val) {
                ite->next = left;
                ite = ite->next;
                left = left->next;
            } else {
                ite->next = right;
                ite = ite->next;
                right = right->next;
            }
        }
        if (left) {
            ite->next = left;
        } else {
            ite->next = right;
        }
        return ans->next;
    }
};
