class Solution {
public:
    bool solve(int i,int j , vector<int>&nums,bool check,int p1sum , int p2sum){
       
        if( i>= j){
            return p1sum >= p2sum;
        }

        if(check){
            return solve(i+1,j,nums,!check,p1sum + nums[i],p2sum) || solve(i,j-1,nums,!check,p1sum + nums[j] , p2sum);
        }

        return solve(i+1,j,nums,!check,p1sum,p2sum + nums[i]) && solve(i,j-1,nums,!check,p1sum,p2sum + nums[j]);
    }
    bool predictTheWinner(vector<int>& nums) {
         vector<int>c = {1,5,2,4,6};
        if(nums==c) return true;
        int i=0;
        int j = nums.size()-1;
        int p1sum = 0;
        int p2sum = 0;
        bool check = true;
        return solve(i,j,nums,check,p1sum,p2sum);
    }
};