class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int currsum = 0;
        int sum = 0;
        int n = nums.size();
        bool check_break = false;
        unordered_map<int,bool>m;
        m[nums[0]] = true;
        if(n==1) return nums[0] + 1;
        maxi = max(maxi,nums[0]);
        mini = min(mini,nums[0]);
        for(int i=1;i<nums.size();i++){
             m[nums[i]] = true;
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
            if(!check_break){
                if(nums[i] == (nums[i-1]+1)){
                    if(sum == 0 ){
                        sum = sum + nums[i-1]+ nums[i];
                    }else{
                        sum = sum + nums[i];
                    }
                }else{
                    check_break = true;
                }
            }
        }
        if(sum==0){
            int check = nums[0];
           while(true){
             if(m.find(check)==m.end()){
                return check;
            }
            check++;
           }
        }
        while(true){
            if(m.find(sum)==m.end()){
                return sum;
            }
            sum++;
        }
        return 0;
    }
};