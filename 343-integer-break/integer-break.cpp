class Solution {
public:
    long long solve(int count ,int n,vector<int>&dp){
        if(n==1){
            return 1;
        }
        if(n==0){
            return count >= 2;
        }
        if(dp[n]!=-1) return dp[n];
        long long ans = INT_MIN;
        for(int i=1;i<=n;i++){
            long long take = i * solve(count +1 ,n-i,dp);
            ans = max(ans,take);
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        int count = 0;
        long long ans = solve(count , n,dp);
        cout<<ans;
        return ans;
    }
};