class Solution {
public:
    int parent(int node , unordered_map<int,int>&par){
        if(par[node]==node){
            return node;
        }
        return par[node] = parent(par[node],par);
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>par;
        unordered_map<int,int>len;
        unordered_map<int,int>check;
        int n = nums.size();
        for(auto i : nums){
            par[i] = i;
            len[i] = 1;
        }
        for(int i=0;i<n;i++){
            int idx = nums[i];
            int first = INT_MAX;
            int second = INT_MAX;
            if(check.find(idx)!=check.end()){
                continue;
            }
            if(check.find(idx+1)!=check.end()){
                first = idx+1;
            }
            if(check.find(idx-1)!=check.end()){
                second = idx-1;
            }
            if(first==INT_MAX && second==INT_MAX){
                len[idx] = 1;
                par[idx] = idx;
            }else if(first!=INT_MAX && second==INT_MAX){
                int f_par = parent(first,par);
                int leng = len[f_par];
                par[idx] = f_par;
                len[f_par] = 1 + leng;
            }else if(first==INT_MAX && second!=INT_MAX){
                int s_par = parent(second,par);
                int leng = len[s_par];
                par[idx] = s_par;
                len[s_par] = 1 + leng;
            }else{
                int f_par = parent(first,par);
                int leng = len[f_par];
                 int s_par = parent(second,par);
                int leng2 = len[s_par];
                par[s_par] = f_par;
                len[f_par] = 1 + leng + leng2;
            }
            check[idx] = true;
        }
        int ans = INT_MIN;
        for(auto i : len){
            ans = max(ans,i.second);
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};