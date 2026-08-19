class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(),intervals.end());
        int k = 0;
        for(int i = 0;i < intervals.size();i++){
            if(intervals[i][0] <= intervals[k][1]){
               intervals[k][1] = max(intervals[k][1],intervals[i][1]);
            }else{
                intervals[++k] = intervals[i];
            }
        }
        intervals.resize(k+1);
        return intervals;
    }
};