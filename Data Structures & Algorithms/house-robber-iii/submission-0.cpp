class Solution {
public:
    int rob(TreeNode* root) {
       auto result = dfs(root);
       return max(result.first,result.second); 
    }
private:
   pair<int,int> dfs(TreeNode* root){
    if(!root){
        return {0,0};
    }
    auto left = dfs(root->left);
    auto right = dfs(root->right);
    int withroot =  root->val + left.second + right.second;
    int withoutroot = max(left.first,left.second)+ max(right.first,right.second);
    return {withroot,withoutroot};
   }
};