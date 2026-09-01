class Solution {
public:
   vector<vector<int>> result;
   void bt(vector<int> &curr,int start,vector<int> &nums){
    result.push_back(curr);
    for(int i = start;i < nums.size();i++){
        if (i > start && nums[i] == nums[i - 1]) continue;
        curr.push_back(nums[i]);
        bt(curr,i+1,nums);
        curr.pop_back();
    }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        bt(curr,0,nums);
        return result;
    }
};