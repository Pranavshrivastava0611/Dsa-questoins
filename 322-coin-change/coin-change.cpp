class Solution {
public:
    // int solve(int index, vector<int>&coins,int amount,vector<vector<int>>&dp){
    //     if(index == 0){
    //         if(amount%coins[index]!=0){
    //             return 100001;
    //         }else{
    //             return amount/coins[index];
    //         }
    //     }
    //     if(dp[index][amount]!=-1) return dp[index][amount];
    //     int ans = 100001;
    //     if(coins[index] <= amount){
    //         ans = min(ans,1+ solve(index,coins,amount - coins[index],dp));
    //     }
    //     ans = min(ans,solve(index-1,coins,amount,dp));
    //     return dp[index][amount] = ans;
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int i=0;i<=amount;i++){
             if(i%coins[0]!=0){
                dp[0][i] = 100001;
            }else{
                dp[0][i] =  i/coins[0];
            }
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int ans = 100001;
                if(coins[i] <= j){

                ans = min(ans,1+ dp[i][j-coins[i]]);

                 }
                ans  = min(ans,dp[i-1][j]);

                dp[i][j] = ans;
            }
        }
        return dp[n-1][amount]==100001 ? -1 : dp[n-1][amount];
    }
};