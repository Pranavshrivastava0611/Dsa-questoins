class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        int i =0;
        int j=0;
        int ans = 0;
        long long pro = 1;
        if(k <= 1) return 0;
        while(j<size){
            pro = pro * nums[j];
            while( i <= j && pro >= k){
                pro /= nums[i];
                i++;
            }
            ans = ans + (j-i+1);
            j++;
        }
        return ans;
    }
};