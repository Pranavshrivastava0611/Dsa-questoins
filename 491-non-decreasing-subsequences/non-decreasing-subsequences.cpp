class Solution {
public:
    struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;

        for (int x : v) {
            hash ^= hash + x + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
    void solve(int index , int prev, vector<int>&nums,vector<int>&str,unordered_set<vector<int>,VectorHash>&ans){
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
        unordered_set<vector<int>,VectorHash>ans;
        vector<int>str;
        solve(0,-1,nums,str,ans);
       vector<vector<int>> anss(ans.begin(), ans.end());
        return anss;
    }
};