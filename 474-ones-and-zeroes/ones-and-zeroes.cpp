class Solution {
public:
    int solve(int index,int zero , int one,vector<pair<int,int>>&str,vector<vector<vector<int>>>&dp ){
        if(index==str.size()){
            return 0;
        }
        if(one == 0 && zero == 0){
            return 0;
        }
        if(dp[index][zero][one]!=-1) return dp[index][zero][one];

        int take = 0;
        int z = str[index].first;
        int o = str[index].second;
        if(one >= o && zero >= z){
            take = 1 + solve(index+1,zero-z,one-o,str,dp);
        }
        int ntake = solve(index+1,zero,one,str,dp);
        return dp[index][zero][one] = max(take,ntake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>str;
        for(int i=0;i<strs.size();i++){
            int one = 0;
            int z = 0;
            for(auto  i : strs[i]){
                if(i=='1') one++;
                else z++;
            }
            str.push_back({z,one});
        }
        int s = str.size();
        vector<vector<vector<int>>>dp(s,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans = solve(0,m,n,str,dp);
        cout<<ans;
        return ans;
    }
};