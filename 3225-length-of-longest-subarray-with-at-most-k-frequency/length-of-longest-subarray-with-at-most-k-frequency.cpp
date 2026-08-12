class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>str;
        int n = nums.size();
        int ans = 0;
        int i=0;
        int j=0;
        while(j<n){
            str[nums[j]]++;
            while(i<j && str[nums[j]] > k){
                str[nums[i]]--;
                if(str[nums[i]]==0){
                    str.erase(nums[i]);
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        cout<<ans;
        return ans;
    }
};