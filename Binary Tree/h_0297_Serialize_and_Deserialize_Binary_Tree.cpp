/*
  設計兩個API serialize和deserialize，
  serialize將二元樹轉換成對應的字串，deserialize將字串轉換成對應的二元樹

  以下利用前序走訪做出serialize和deserialize
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> str = split(data, ",");
        return deserialize(str);
    }

    // Auxiliary function
    void serialize(TreeNode* root, string& res) {
        if (!root) {
            res += "null,";
            return;
        }
        res += to_string(root->val) + ",";
        serialize(root->left, res);
        serialize(root->right, res);
    }

    TreeNode* deserialize(queue<string>& data) {
        if (data.empty()) return nullptr;
        string first = data.front(); data.pop();
        if (first == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(first));
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }

    queue<string> split(string data, string delimiter) {
        queue<string> res;
        int pos = 0;
        while ((pos = data.find(delimiter)) != string::npos) {
            res.push(data.substr(0, pos));
            data.erase(0, pos + delimiter.length());
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
