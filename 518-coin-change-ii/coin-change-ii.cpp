class Solution {
public:
    int solve(int index,int sum,vector<int>&coins,vector<vector<int>>&dp){
        if(index==coins.size()){
            return 0;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];
        if(sum < 0){
            return 0;
        }
        if(sum==0) return 1;

        int take = 0;
        if(sum >=coins[index]){
            take += solve(index,sum - coins[index],coins,dp);
        }
        int ntake = solve(index+1,sum,coins,dp);
        return dp[index][sum] = take + ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        bool taken = false;
        return solve(0,amount,coins,dp);
    }
};