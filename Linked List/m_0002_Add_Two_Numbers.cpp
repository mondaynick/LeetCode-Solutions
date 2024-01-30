/*
  給定兩個鏈結串列，每個鏈結串列從head到tail分別代表十進位的個位、十位、百位...，輸出以兩鏈結串列相加結果並以鏈結串列表示

  根據定義，遍歷兩鏈結串列    
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* ite = ans;
        int carry = 0;
        while (l1 || l2 || carry) {
            int l1n = (l1) ? (l1->val) : 0;
            int l2n = (l2) ? (l2->val) : 0;
            int temp = l1n + l2n + carry;
            ite->next = new ListNode(temp % 10);
            ite = ite->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            carry = temp / 10;
        }
        return ans->next;
    }
};
