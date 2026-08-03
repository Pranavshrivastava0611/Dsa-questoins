class Solution {
public:
    // int solve(int index , bool buy , vector<int>&prices,vector<vector<int>>&dp){
    //     if(index >= prices.size()){
    //         return 0;
    //     }
    //     if(dp[index][buy]!=-1) return dp[index][buy];

    //     if(buy==false){
    //         return dp[index][buy] = max(solve(index+1,buy,prices,dp),prices[index] + solve(index+2,true,prices,dp));
    //     }

    //     return dp[index][buy] = max(solve(index+1,buy,prices,dp),-prices[index] + solve(index+1,false,prices,dp));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i =n-1;i >=0 ;i--){
            for(int j=0;j<2;j++){
                if(j){
                    dp[i][j] = max(prices[i] + dp[i+2][0],dp[i+1][1]);
                }else{
                    dp[i][j] = max(-prices[i] + dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
        
    }
};