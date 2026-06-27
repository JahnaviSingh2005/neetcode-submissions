class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            res.push_back(nums1[i]);}
        for(int i = 0; i < m; i++){
            res.push_back(nums2[i]);}
        sort(res.begin(), res.end());
        int size = res.size();
        if(size % 2 == 1){ 
        return res[size / 2];
        }
        return (res[size/2] + res[size/2 - 1]) / 2.0;
    }
};