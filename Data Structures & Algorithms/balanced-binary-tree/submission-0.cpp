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
    bool isBalanced(TreeNode* root) {
      return checkheight(root) != -1;  
    }
private:
    int checkheight(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = checkheight(root->left);
        int right = checkheight(root->right);
        if(left == -1) return -1;
        if(right == -1) return -1;
        if(abs(left - right) > 1){
            return -1;
        }
        return 1 + max(left,right);
    }
};
