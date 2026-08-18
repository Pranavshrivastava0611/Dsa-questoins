class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if( k > n) return -1;
        if(k==1){
            vector<int>check(51,0);
            for(auto i  : nums){
                check[i]++;
            }
            int ans = -1;
            for(int i=0;i<51;i++){
                if(check[i]==1){
                    ans = max(ans,i);
                }
            }
            return ans;
        }
        if(k==(nums.size())){
            int ans = -1;
            for(auto i : nums){
                ans = max(ans,i);
            }
            return ans;
        }
        int index = k;
        int j = 0;
        unordered_map<int,int>vis;
        while(j+k <=n){
            if(j <= index){
                vis[nums[j]] = j+1;
            }else{
                vis[nums[j]] = k;
            }
            j++;
        }
        int ans = -1;
        int idx = k-1;
        while(j<n){
            vis[nums[j]] += idx;
            if(idx > 1){
                idx--;
            }
            j++;
        }
        for(auto i : vis){
            cout<<i.first<<" "<<i.second<<endl;
            if(i.second==1){
                ans = max(ans,i.first);
            }
        }
        return ans;
    }
};