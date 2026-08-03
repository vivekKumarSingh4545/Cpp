class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);  
        for (int ind = n - 1; ind >= 0; ind--) {
            int first = INT_MIN, second = INT_MIN, third = INT_MIN;
            first = stoneValue[ind] - dp[ind + 1];
            if (ind + 1 < n)
                second = stoneValue[ind] + stoneValue[ind + 1] - dp[ind + 2];
            if (ind + 2 < n)
                third = stoneValue[ind] + stoneValue[ind + 1] + stoneValue[ind + 2] - dp[ind + 3];
            dp[ind] = max({first, second, third});
        }
        int result = dp[0];
        if (result > 0) return "Alice";
        else if (result < 0) return "Bob";
        else return "Tie";
    }
};