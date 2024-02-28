/*
  給定一N叉樹，求level order traversal，答案用二維陣列表示，每個元素代表每一層

  利用queue加bfs
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty()) {
            vector<int> temp;
            for (int i = Q.size() ; i > 0 ; i--) {
                Node* curr = Q.front();
                Q.pop();
                temp.push_back(curr->val);
                for (auto c: curr->children) {
                    Q.push(c);
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};
