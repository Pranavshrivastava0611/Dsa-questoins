class Solution {
public:
    unordered_map<char,bool>store;
     unordered_map<string,int>strr;
    int solve(int index,int &length,string &str,string &s,string &t,vector<vector<int>>&dp){

        if(index==length){
            return str==t;
        }
        int idx = strr[str];
        if(dp[index][idx]!=-1) return dp[index][idx];
        
        str.push_back(s[index]);
        int take = 0;
        if(strr.find(str)!=strr.end()){
            take = solve(index+1,length,str,s,t,dp);
        }
        str.pop_back();
        int ntake = solve(index+1,length,str,s,t,dp);

        return dp[index][idx] = take + ntake;

    }
    int numDistinct(string s, string t) {
        for(auto c : t){
            store[c] = true;
        }
        int length = s.length();
        string check = "";
        int length2 = t.length();
        strr[""] = 0;
        for(int i=0;i<length2;i++){
            check = check + t[i];
            strr[check] = i+1;
        }
        vector<vector<int>>dp(length+1,vector<int>(length2+1,-1));
        string str ="";
        int ans = solve(0,length,str,s,t,dp);
        return ans;
    }
};