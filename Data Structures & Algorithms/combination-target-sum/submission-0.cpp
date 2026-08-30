class Solution {
public:
   vector<vector<int>> result;
   void dfs(int i,vector<int> &currlist,int total,vector<int> &nums,int target){
    if(total == target){
        result.push_back(currlist);
        return;
    }
    if(i >= nums.size() || total > target){return;}
    currlist.push_back(nums[i]);
    dfs(i,currlist,total +nums[i],nums,target);
    currlist.pop_back();
    dfs(i+1,currlist,total,nums,target);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> currlist;
       dfs(0,currlist,0,candidates,target);
       return result; 
    }
};