class Solution {
public:
    bool solve(int index,int i,int j , string s1 , string s2 , string s3 ,vector<vector<int>>&dp){
        if(index==s3.length()) return true;
        if(s1[i]!=s3[index]&& s2[j]!=s3[index]){
            return false;
        }
        if(dp[i][j]!=2) return dp[i][j];

        bool ans = false;
         if (i < s1.length() && s1[i] == s3[index]) {
            ans = ans || solve(index + 1, i + 1, j, s1, s2, s3, dp);
        }

        if (j < s2.length() && s2[j] == s3[index]) {
            ans = ans || solve(index + 1, i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j]= ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int t = s3.length();
        if(t!=(m+n)) return false;
        int index = 0;
        int i =0;
        int j =0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,2));
        bool ans = solve(index,i,j,s1,s2,s3,dp);
        cout<<ans;
        return ans;
    }
};