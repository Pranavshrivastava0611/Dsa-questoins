class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = requests[0];
        int m = requests.size();
        for(int i=0;i<m;i++){
            if(i+1 < m){
                ans += abs(requests[i]-requests[i+1]);
            }
        }
        return ans;
    }
};