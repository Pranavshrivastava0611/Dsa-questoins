class Solution {
public:
    int solve(vector<int>&nums,vector<bool>check){
        for(int i=0;i<nums.size();i++){
            int value = nums[i];
            if(value==6 || value==7){
                check[1]=check[2]=true;
            }
            if(value==4 || value==5){
                check[1]=check[0] = true;
            }
            if(value==2 || value==3 || value==4 || value==5){
                check[0] = true;
            }
            if(value==4 || value==5 || value==6 || value==7){
                check[1] = true;
            }
            if(value==6 || value==7 || value==8 || value==9){
                check[2] = true;
            }
        }
        int count = 0;
        for(int i=0;i<3;i++){
            if(!check[i]){
                count++;
            }
        }
        if(count==3){
            count = 2;
        }else if(count==2){
            count = 1;
        }
        return count;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int,vector<int>>str;
        for(int i=0;i<r.size();i++){
            str[r[i][0]].push_back(r[i][1]);
        }
        // sort(r.begin(),r.end());
        int left = n;
        int total = 0;
        for(auto i : str){
            vector<bool>check(3,false);
            left--;
            int ans = solve(i.second,check);
            cout<<i.first<<" "<<ans<<endl;
            total = total + ans;
        }
        total = total + (2*left);
        cout<<total;
        return total;
    }
};