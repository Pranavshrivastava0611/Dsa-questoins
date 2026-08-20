class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int index1 = 0;
        int index2 = 0;
        for(int i=2;i<nums.size();i++){
            if(arr1[index1] > arr2[index2]){
                arr1.push_back(nums[i]);
                index1++;
            }else{
                arr2.push_back(nums[i]);
                index2++;
            }
        }
        vector<int>result;
        for(auto i : arr1){
            result.push_back(i);
        }
        for(auto i : arr2){
            result.push_back(i);
        }
        return result;
    }
};