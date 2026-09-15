class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>str(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int k = rowShift[i]%n;
            for(int j=0;j<n;j++){
                int idx = (j-k+n)%n;
                str[i][idx] = grid[i][j];
            }
        }
        for(int j=0;j<n;j++){
            int k = colShift[j]%n;
            for(int i=0;i<n;i++){
                int idx =  (i-k+n)%n;
                grid[idx][j] = str[i][j];
            }
        }
        return grid;
    }
};