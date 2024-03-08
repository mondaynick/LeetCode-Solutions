/*
  給定一鏈結串列和left、right，將鏈結串列第left到right的節點(假設從1開始)反轉並回傳

  紀錄一個節點指到left的前面，和一個節點指到right的後面，將left到right的節點依序放到堆疊，最後串起來
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* res = new ListNode;
        res->next = head;

        ListNode *beforeLeft = res, *afterRight = res;
        stack<ListNode*> S;
        left -= 1;
        right += 1;
        while (left--) {
            beforeLeft = beforeLeft->next;
            afterRight = afterRight->next;
            right--;
        }
        while (right--) {
            afterRight = afterRight->next;
            S.push(afterRight);
        }
        S.pop();

        while (!S.empty()) {
            beforeLeft->next = S.top();
            S.pop();
            beforeLeft = beforeLeft->next;
        }
        beforeLeft->next = afterRight;
        return res->next;
    }
};
