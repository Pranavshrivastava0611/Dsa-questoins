class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>std;
        for(auto x : nums){
            auto it = lower_bound(std.begin(),std.end(),x);
            if(it==std.end()){
                std.push_back(x);
            }else{
                *it = x;
            }
        }
        return std.size();
    }
};