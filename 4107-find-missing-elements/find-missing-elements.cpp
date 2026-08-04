class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        vector<int>str(101,-1);
        for(auto i : nums){
            maxi = max(maxi,i);
            mini = min(mini,i);
            str[i] = 0;
        }
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            if(str[i]==-1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};