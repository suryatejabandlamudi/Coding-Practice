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
        if(root == NULL) return "#";
        return to_string(root->val) +","+serialize(root->left)+","+serialize(root->right);        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return my_deserialize(s);
    }
    
    TreeNode* my_deserialize(stringstream& s)
    {
        string curr;
        getline(s,curr,',');
        if(curr == "#")
        {
            return NULL;
        }
        
        TreeNode* node = new TreeNode(stoi(curr));
        node->left = my_deserialize(s);
        node->right = my_deserialize(s);
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));