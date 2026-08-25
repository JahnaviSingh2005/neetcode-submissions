class Solution {
public:
    int backtrack(vector<int>& nums, int index, int currentXOR) {
    if (index == nums.size()) {
        return currentXOR;
    }
    int exclude = backtrack(nums, index + 1, currentXOR);
    int include = backtrack(nums, index + 1, currentXOR ^ nums[index]);
    return exclude + include;
}
int subsetXORSum(vector<int>& nums) {
    return backtrack(nums, 0, 0);
}
};