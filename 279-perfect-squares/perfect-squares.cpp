class Solution {
public:
    int solve(int n, vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];

        int sqr = sqrt(n);
        int ans = INT_MAX;
        for(int i=sqr;i>=1;i--){
            ans = min(ans,1 + solve(n-(i*i),dp));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        int count = 0;
        int ans = solve(n,dp);
        return ans;
    }
};