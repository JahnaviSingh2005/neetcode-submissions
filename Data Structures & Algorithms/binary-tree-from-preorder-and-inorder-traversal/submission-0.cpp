class Solution {
private:
    TreeNode* splitTree(vector<int>& preOrder, unordered_map<int, int>& inOrderIndexMap, 
                        int rootIndex, int left, int right) {
        
        TreeNode* root = new TreeNode(preOrder[rootIndex]);
        int mid = inOrderIndexMap[preOrder[rootIndex]];
        
        if (mid > left) {
            root->left = splitTree(preOrder, inOrderIndexMap, 
                                   rootIndex + 1, left, mid - 1);
        }
        
        if (mid < right) {
            root->right = splitTree(preOrder, inOrderIndexMap, 
                                    rootIndex + mid - left + 1, mid + 1, right);
        }
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        unordered_map<int, int> inOrderIndexMap;
        for (int i = 0; i < inOrder.size(); ++i) {
            inOrderIndexMap[inOrder[i]] = i;
        }
        
        return splitTree(preOrder, inOrderIndexMap, 0, 0, inOrder.size() - 1);
    }
};