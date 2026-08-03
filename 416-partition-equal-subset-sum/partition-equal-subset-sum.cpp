class Solution {
public:
    bool solve(int index , int sum , vector<int>&nums,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(sum < 0) return false;
        if(index==0){
            return nums[0]==sum;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];

        bool take = solve(index-1,sum-nums[index],nums,dp);
        bool ntake = solve(index-1,sum,nums,dp);
        return dp[index][sum] = take || ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        if(sum&1) return false;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));
        return solve(n-1,sum/2,nums,dp);
    }
};