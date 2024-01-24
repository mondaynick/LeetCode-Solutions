/*
  給定前序走訪和中序走訪，還原整棵二元樹

  利用走訪定義
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
    map<int, int> dict;
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        int mid = dict[preorder[preStart]];
        int leftLen = mid - inStart;
        int rightLen = inEnd - mid;
        TreeNode* root = new TreeNode(preorder[preStart]);
        root->left = build(preorder, preStart+1, preStart+leftLen, inorder, inStart, inStart+leftLen-1);
        root->right = build(preorder, preEnd-rightLen+1, preEnd, inorder, inEnd-rightLen+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0 ; i < inorder.size() ; i++) dict[inorder[i]] = i;
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
