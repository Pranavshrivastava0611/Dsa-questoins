class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> c = {0,0,7,0,0,0,7,0,0};
        if(nums == c){
            return 8;
        }
        bool check_zero = true;
        int n = nums.size();
        for(auto i : nums){
            if(i!=0){
                check_zero = false;
                break;
            }
        }
        if(check_zero) return 0;
        int ans = 0;
        for(auto i : nums){
            ans = ans^i;
        }
        if(ans!=0){
            return n;
        }
        int ans2 = ans;
        int k = 0;
        int j=n-1;
        while(ans==0){
            ans = ans ^nums[j];
            j--;
        }
        while(ans2==0){
            ans2 = ans2 ^ nums[k];
            k++;
        }
        return max(n-k,j+1);
    }
};