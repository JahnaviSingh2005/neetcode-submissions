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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
       if(!root) return res;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        int levelsize = q.size();
        int lastval = 0;
        for(int i = 0 ;i < levelsize ;i++){
            TreeNode* node = q.front();
            q.pop();
            lastval = node->val;
            if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }        
        }
        res.push_back(lastval);
       } 
       return res;
    }
};