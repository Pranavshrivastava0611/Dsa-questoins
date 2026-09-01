class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>next(n,INT_MAX);
        vector<int>back(n,INT_MAX);
        int maxi = height[n-1];
        for(int i=n-1;i>=0;i--){
            if(maxi==INT_MIN){
                next[i] = INT_MAX;
            }else{
                if(height[i] >= maxi){
                    next[i] = INT_MAX;
                    maxi = height[i];
                }else{
                    next[i] = maxi;
                }
            }
        }
        maxi = height[0];
        for(int i=0;i<n;i++){
            if(maxi==INT_MIN){
                back[i] = INT_MAX;
            }else{
                if(height[i] >= maxi){
                    back[i] = INT_MAX;
                    maxi = height[i];
                }else{
                    back[i] = maxi;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(next[i]==INT_MAX || back[i]==INT_MAX){
                continue;
            }else{
                int add = min(next[i],back[i])-height[i];
                ans += add;
            }
        }
        return ans;
    }
};