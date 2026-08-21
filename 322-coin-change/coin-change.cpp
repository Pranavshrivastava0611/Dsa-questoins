class Solution {
public:     
    int solve(int index,int sum ,vector<int>&coins,vector<vector<int>>&dp){
        if(index==coins.size()){
            return INT_MAX;
        }
        if(dp[index][sum]!=100001) return dp[index][sum];
        if(sum < 0){
            return INT_MAX;
        }
        if(sum==0) return 0;

        int take = INT_MAX;
        if(sum >=coins[index]){
            take = min(take,solve(index,sum-coins[index],coins,dp));
            if(take!=INT_MAX){
                take = 1+take;
            }
        }
        int ntake = solve(index+1,sum,coins,dp);
        return dp[index][sum] = min(take,ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,100001));
        int sum =0;
        int ans = solve(0,amount,coins,dp);
        cout<<ans;
        if(ans==INT_MAX) return -1;
        return ans;
    }
};