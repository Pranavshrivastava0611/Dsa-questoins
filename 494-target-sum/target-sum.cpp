class Solution {
public:
    int solve(int index,int sum,int count, vector<int>&nums,int target,vector<vector<int>>&dp){
        if(index==nums.size()){
            return sum==target;
        }
        if(dp[index][sum+count]!=-1)return dp[index][sum + count];

        int plus = solve(index+1,sum + nums[index],count,nums,target,dp);
        int minus = solve(index+1,sum - nums[index],count,nums,target,dp);

        return dp[index][sum + count] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for(auto i : nums){
            count += i;
        }
        vector<vector<int>>dp(n,vector<int>((2*count)+1,-1));
        int sum = 0;
        int ans = solve(0,sum,count,nums,target,dp);
        return ans;
    }
};