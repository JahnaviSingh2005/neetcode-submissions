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
    dfs(i+1,currlist,total +nums[i],nums,target);
    currlist.pop_back();
    while(i+1 < nums.size()&&nums[i] == nums[i+1]){
        i++;
    }
    dfs(i+1,currlist,total,nums,target);
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> currlist;
        dfs(0,currlist,0,candidates,target);
        return result;
    }
};