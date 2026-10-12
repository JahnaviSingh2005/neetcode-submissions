class Solution {
public:
   int robl(vector<int>& nums,int start,int end){
    int n = end - start +1;
    vector<int> dp(n);
    if(n <= 0) return 0;
    if(n == 1) return nums[start];
    dp[0] = nums[start];
    dp[1] = max(nums[start],nums[start+1]);
    for(int i = 2;i < n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+nums[start+i]);
    }
    return dp[n-1];
   }
    int rob(vector<int>& nums) {
      int n = nums.size();
      if(n == 1) return nums[0];
       return max(robl(nums, 0, n - 2), robl(nums, 1, n - 1));  
    }
};
