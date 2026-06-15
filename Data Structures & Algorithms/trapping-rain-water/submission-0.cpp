class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int leftmax = height[l];
        int rightmax = height[r];
        int total = 0;
        while(l < r){
            if(leftmax < rightmax){
                l++;
                leftmax = max(leftmax,height[l]);
                total += leftmax - height[l];
            }else{
                r--;
                rightmax = max(rightmax,height[r]);
                total += rightmax - height[r];
            }
        }
        return total;
    }
};