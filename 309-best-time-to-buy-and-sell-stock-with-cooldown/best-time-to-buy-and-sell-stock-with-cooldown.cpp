class Solution {
public:
    int solve(int index , bool buy , vector<int>&prices,vector<vector<int>>&dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1) return dp[index][buy];

        if(buy==false){
            return dp[index][buy] = max(solve(index+1,buy,prices,dp),prices[index] + solve(index+2,true,prices,dp));
        }

        return dp[index][buy] = max(solve(index+1,buy,prices,dp),-prices[index] + solve(index+1,false,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};