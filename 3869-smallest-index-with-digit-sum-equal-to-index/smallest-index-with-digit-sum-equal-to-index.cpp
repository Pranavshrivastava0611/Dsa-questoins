class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            int n = nums[i];
            while(n){
                sum = sum + (n%10);
                n = n/10;
            }
            nums[i] = sum;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i) return i;
        }
        return -1;
    }
};