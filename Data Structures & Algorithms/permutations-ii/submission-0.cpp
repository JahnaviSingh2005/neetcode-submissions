class Solution {
public:
    vector<vector<int>> res;
    void bt(int index, vector<int>& nums) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int i = index; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[index], nums[i]);
            bt(index + 1, nums);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        bt(0, nums);
        return res;
    }
};