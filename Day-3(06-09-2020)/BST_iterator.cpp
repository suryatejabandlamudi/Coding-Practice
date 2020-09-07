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
class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* current;
    BSTIterator(TreeNode* root) {
        current = root;
    }
    
    /** @return the next smallest number */
    int next() {
        
        while(current!= NULL)
        {
            s.push(current);
            current = current->left;
        }
        
        TreeNode* tmp = s.top();
        s.pop();
        current = tmp->right;
        return tmp->val;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current!= NULL || !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */