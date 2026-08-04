class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>str;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto i : nums){
            str[i]++;
            maxi = max(maxi,i);
            mini = min(mini,i);
        }
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            if(str.find(i)==str.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};