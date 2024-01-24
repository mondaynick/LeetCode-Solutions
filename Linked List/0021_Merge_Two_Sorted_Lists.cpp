/*
  給定兩個升冪排序的鏈結串列，輸出將兩個鏈結串列合併並且以升冪排序

  比較鏈結串列的head
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* ite = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ite->next = list1;
                list1 = list1->next;
            } else {
                ite->next = list2;
                list2 = list2->next;
            }
            ite = ite->next;
        }
        if (list1) {
            ite->next = list1;
        } else if (list2) {
            ite->next = list2;
        }
        return dummy.next;
    }
};
