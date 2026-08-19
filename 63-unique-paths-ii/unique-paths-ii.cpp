class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int m = nums.size();int n = nums[0].size();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
        dp[m-1][n-1] = 1;
        if(nums[m-1][n-1]==1) return 0;
        if(nums[0][0]==1) return 0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                if(nums[i][j]==1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return (int)dp[0][0];
    }
};