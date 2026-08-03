class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
       long long ans = LLONG_MIN;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                long long gcdd = gcd(nums[i],nums[j]);
                gcdd = gcdd*gcdd;
                long long first = (long long)((long long)(nums[i]) * (long long)(nums[j]));
                ans = max(ans,first/gcdd);
            }
        }
        return ans;
    }
};