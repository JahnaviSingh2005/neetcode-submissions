class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
       int sum = 0;
       for(int match : matchsticks){
        sum += match;
       } 
       if(sum % 4 != 0) return false;
       vector<int> sides(4,0);
       int target  = sum/4;
       sort(matchsticks.rbegin(), matchsticks.rend());
       if (matchsticks[0] > target) return false;
       return dfs(matchsticks,sides,0,target);
    }
    bool dfs(vector<int> &matchsticks,vector<int> &sides,int i,int target){
        if(i == matchsticks.size()){
           return sides[0] == target && sides[1] == target && 
                 sides[2] == target && sides[3] == target; 
        }
        for(int j = 0;j < 4;j++){
           if(sides[j] + matchsticks[i] <= target){
            sides[j] += matchsticks[i];
            if (dfs(matchsticks, sides, i + 1, target)) {
                 return true;
                }
                sides[j] -= matchsticks[i];
           }
        }
        return false;
    }
};