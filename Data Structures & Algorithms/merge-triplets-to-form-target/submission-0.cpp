class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
       vector<int> curr = {0,0,0};
       for(auto &t : triplets){
           if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
            curr[0] = max(curr[0],t[0]);
            curr[1] = max(curr[1],t[1]);
            curr[2] = max(curr[2],t[2]);
           }
       }
       return curr == target;
    }
};