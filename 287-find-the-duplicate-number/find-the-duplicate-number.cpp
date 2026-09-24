class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        for(int i=0;i<size;i++){
            int idx = abs(nums[i]);
            if(nums[idx] < 0){
                return idx;
            }else{
                nums[idx] = -nums[idx];
            }
        }
        return -1;

    }
};