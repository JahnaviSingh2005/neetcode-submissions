class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l = 0;
        int r = people.size()-1;
        int cnt = 0;
        while(l <= r){
           int remain = limit - people[r--];
            cnt++;
            if(l <= r && remain >= people[l]){
                l++;
            }
        }
        return cnt;
    }
};