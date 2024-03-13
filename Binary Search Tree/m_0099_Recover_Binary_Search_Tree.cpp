/*
  給定一棵二元樹，交換兩個節點的數值將其還原成一棵二元搜尋樹

  因為二元搜尋樹其中序尋訪必為其節點值從小排到大的結果，假設一棵二元搜尋樹其中序尋訪如下
  1 | 2 | 3 | 4 | 5 | 6 | 7
  我們將2和6互換，得到以下
  1 | 6 | 3 | 4 | 5 | 2 | 7
  從左到右尋訪時，當走訪到3發現比前面的6還要小，第一次我們紀錄前面的節點6記作first，
  當走訪到2時發現比前面的5還要小，第二次我們紀錄當前的節點2記作last，
  最後，將first和last的數值交換即可還原一棵二元搜尋樹
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* last = nullptr;
    void traversal(TreeNode* root) {
        if (root) {
            traversal(root->left);
            if (prev && prev->val > root->val) {
                if (!first) first = prev;
                last = root;
            }
            prev = root;
            traversal(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        traversal(root);
        swap(first->val, last->val);
    }
};
