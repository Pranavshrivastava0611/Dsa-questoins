class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,1);
        vector<int>suf(n,1);
        int p = 1;
        int s = 1;
        for(int i=0;i<n;i++){
            pre[i] = p;
            p = p*nums[i];
        }
        for(int i=n-1;i>=0;i--){
            suf[i] = s;
            s = s *nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = pre[i]*suf[i];
        }
        return ans;
    }
};