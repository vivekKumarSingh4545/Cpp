class Solution {
public:
    bool fun(vector<int>& p, int i, int j, int aliceSum, int bobSum, int turn, vector<vector<int>>& dp){
        if(i>j){
            return aliceSum>bobSum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(turn){
            return dp[i][j] = fun(p, i+1, j, aliceSum+p[i], bobSum, 1-turn, dp) || fun(p, i, j-1, aliceSum+p[j], bobSum, 1-turn, dp);
        }
        else{
            return dp[i][j] = fun(p, i+1, j, aliceSum, bobSum+p[i], 1-turn, dp) || fun(p, i, j-1, aliceSum, bobSum+p[j], 1-turn, dp);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fun(piles, 0, n-1, 0, 0, 1, dp);
    }
};