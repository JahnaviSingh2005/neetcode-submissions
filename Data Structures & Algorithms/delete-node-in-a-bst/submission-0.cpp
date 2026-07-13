class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }
        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            if(!root->left){return root->right;}
            else if(!root->right){return root->left;}
            else{
                TreeNode* curr = root->right;
                while(curr->left){
                    curr = curr->left;
                }
                root->val = curr->val;
                root->right = deleteNode(root->right,root->val); 
            }
        }
        return root;

    }
};