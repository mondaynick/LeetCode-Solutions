/*
  給定一個單向連結串列的head，回傳該鏈結串列中的數字是否回文

  先透過雙指標找到鏈結串列的中心點，根據奇數和偶數節點的不同case如下：
  奇數  1      -> 2       ->3      -> 2      -> 1      -> NULL
       (head)              (slow)              (fast)
  偶數  1      -> 2      -> 2      -> 1      -> NULL
       (head)              (slow)              (fast)
  如果鏈結串列的fast沒走到NULL代表該鏈結串列為奇數個節點，需再將slow往前走一步：
  奇數  1      -> 2       ->3      -> 2      -> 1      -> NULL
       (head)                        (slow)              (fast)
  偶數  1      -> 2      -> 2      -> 1      -> NULL
       (head)              (slow)              (fast)
  從slow開始反轉後面的鏈結串列後，即可開始比較回文
  奇數  1      -> 2       ->3      -> 2      <- 1      
       (left)                        v         (right)
                                    NULL
  偶數  1      -> 2      -> 2      <- 1
       (left)              v         (right)
                          NULL
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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *prev = head, *curr = head->next;
        prev->next = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        /* Find the middle of linked list */
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;

        /* Reverse the linked list */
        ListNode* left = head;
        ListNode* right = reverse(slow);

        /* Check whether is palindrome linked list */
        while (right) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
