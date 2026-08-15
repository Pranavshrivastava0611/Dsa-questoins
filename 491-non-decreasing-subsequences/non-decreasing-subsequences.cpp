class Solution {
public:
    void solve(int index , int prev, vector<int>&nums,vector<int>&str,set<vector<int>>&ans){
        if(index >= nums.size()){
            if(str.size() >=2 ){
                ans.insert(str);
                return ;
            }
            return ;
        }
        if(prev==-1 || nums[index] >= nums[prev]){
            str.push_back(nums[index]);
            solve(index+1,index,nums,str,ans);
            str.pop_back();
        }
        solve(index+1,prev,nums,str,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>str;
        solve(0,-1,nums,str,ans);
       vector<vector<int>> anss(ans.begin(), ans.end());
        return anss;
    }
};