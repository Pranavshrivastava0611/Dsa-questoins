//these problems are called unbounded knapsack problems,where the 

class Solution {
public:     
    // int solve(int index,int sum ,vector<int>&coins,vector<vector<int>>&dp){
    //     if(index==coins.size()){
    //         return INT_MAX;
    //     }
    //     if(dp[index][sum]!=100001) return dp[index][sum];
    //     if(sum < 0){
    //         return INT_MAX;
    //     }
    //     if(sum==0) return 0;

    //     int take = INT_MAX;
    //     if(sum >=coins[index]){
    //         take = min(take,solve(index,sum-coins[index],coins,dp));
    //         if(take!=INT_MAX){
    //             take = 1+take;
    //         }
    //     }
    //     int ntake = solve(index+1,sum,coins,dp);
    //     return dp[index][sum] = min(take,ntake);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        // int sum =0;
        // int ans = solve(0,amount,coins,dp);
        // cout<<ans;
        // if(ans==INT_MAX) return -1;
        // return ans;
        // int n = coins.size();
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                int take = INT_MAX;
                 if(j >=coins[i]){
                take = min(take,dp[i][j-coins[i]]);
                if(take!=INT_MAX){
                take = 1+take;
                     }
                }
                  int ntake = dp[i+1][j];
                dp[i][j] = min(take,ntake);
            }
        }
        return dp[0][amount]==INT_MAX ? -1 : dp[0][amount];
    }
};