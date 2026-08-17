class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> mp;
        for(int i = 0;i < s.length();i++){
            mp[s[i]] = i;
        }
        vector<int> result;
        int end = 0;
        int size = 0;
        for(int i =0;i<s.length();i++){
            size++;
            end = max(end,mp[s[i]]);
            if(i == end){
                result.push_back(size);
                size = 0;
            }
        }
        return result;
    }
};