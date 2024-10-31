/*
  給定連通無向圖中某個節點的參考，回傳對該圖深複製的結果

  利用dfs
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> Copied;
public:
    Node* cloneGraph(Node* node) {
        if (nullptr == node) return nullptr;
        if (!Copied.count(node)) {
            Copied[node] = new Node(node->val);
            for (Node* ite: node->neighbors) {
                Copied[node]->neighbors.push_back(cloneGraph(ite));
            }
        }
        return Copied[node];
    }
};
