class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size==1) return nums[0];
        int i=1;int j = size-2;
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[size-1]!=nums[size-2]) return nums[size-1];
        while(i <=j){
            int mid = i + (j-i)/2;
            if(nums[mid+1]!=nums[mid] && (nums[mid-1]!=nums[mid])){
                return nums[mid];
            }else if(nums[mid+1]==nums[mid]){
                if ((size - (mid + 2)) % 2 == 0){
                    j = mid-1;
                }else{
                    i = mid+1;
                }
            }else{
                if((mid-1)%2==0){
                    i = mid+1;
                }else{
                    j = mid-1;
                }
            }
        }
        return -1;
    }
};