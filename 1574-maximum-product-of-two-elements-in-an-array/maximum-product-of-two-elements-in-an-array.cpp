class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int onemax = INT_MIN;
        int secondmax = INT_MIN;
        int size = nums.size();
        for(auto i : nums){
            if(i>onemax){
                secondmax = max(secondmax,onemax);
                onemax = max(onemax,i);
            }else{
                secondmax = max(secondmax,i);
            }
        }
        return (onemax-1)*(secondmax-1);
    }
};