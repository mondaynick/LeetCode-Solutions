/*
  給定一個鏈結串列，其中每個節點的數值不是 0 就是 1 ，代表其二進位表示法，
  回傳將該二進位轉成十進位的值，其中鏈結串列的 head 為 MSB

  遍歷鏈結串列
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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head) {
            result = result * 2 + head->val;
            head = head->next;
        }
        return result;
    }
};
