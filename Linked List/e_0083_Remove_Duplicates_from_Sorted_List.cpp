/*
    給定一鏈結串列，輸出將此鏈結串列刪掉連續重複的元素

    利用two pointer，若prev和curr的元素相同則將prev指向curr->next
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ite = head;
        ListNode* temp = NULL;
        while (ite) {
            temp = ite->next;
            while (temp && temp->val == ite->val) {
                temp = temp->next;
            }
            ite->next = temp;
            ite = ite->next;
        }
        return head;
    }
};
