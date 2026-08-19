class Solution {
public:
    vector<int>dp;
    int solve(int index,vector<int>&nums){
        if(index >= nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];

        int count = index;
        int sum = 0;
        while(count < nums.size() && nums[count]==nums[index]){
            sum += nums[index];
            count++;
        }
        int next = count;
        while (next < nums.size() && nums[next] == nums[index] + 1) {
            next++;
        }
        int take = sum + solve(next,nums);
        int ntake = solve(count,nums);
        return dp[index] = max(take,ntake);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        dp.resize(n,-1);
        int ans = solve(0,nums);
        return ans;
    }
};