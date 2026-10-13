class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        if (s.empty() || s[0] == '0') return 0;
        dp[0] = 1;
        dp[1] = 1;
        vector<int> digit;
        for(char c : s){
           digit.push_back(c - '0');
        }
        for(int i = 2;i <=n;i++){
            if(digit[i-1] != 0){
                dp[i] += dp[i-1];
            }
            int twodigit = digit[i-2]*10 + digit[i-1];
            if(twodigit >= 10 && twodigit <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
