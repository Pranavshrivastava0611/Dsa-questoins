class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count= 0;
        float check = (float)((float)(a) / (float)(b));
        for(int i=0;i<nums.size();i++){
            int even = 0;
            int odd = 0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]&1){
                    odd++;
                }else{
                    even++;
                }
            if(odd > 0){
            float check2 = (float)((float)(even) / (float)(odd));
            if(check2 <= check){
                count++;
            }
            }
            }
        }
        return count;
    }
};