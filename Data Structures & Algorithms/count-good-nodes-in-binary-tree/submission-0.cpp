class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
private:
    int dfs(TreeNode* node,int maxval){
        if(!node){
            return 0;
        }
        int res = (node->val >= maxval)? 1: 0;
        maxval = max(node->val,maxval);
        res += dfs(node->left,maxval);
        res += dfs(node->right,maxval);
        return res;
    }
};