class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 0, cnt = 0, sign = -1;
        for (int i = 0; i < (int)arr.size() - 1; i++) {
            int cur = (arr[i] > arr[i + 1]) - (arr[i] < arr[i + 1]);
            cnt = (cur && cur == -sign) ? cnt + 1 : (cur != 0);
            sign = cur;
            res = max(res, cnt);
        }
        return res + 1;
    }
};