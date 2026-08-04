class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>>check;
    bool isSafe(int x, int y){
        return x >= 0 && x<4 && y>=0 && y<3 && check[x][y]!=-1;
    }
    vector<int>vx = {2,2,-2,-2,1,-1,1,-1};
    vector<int>vy = {1,-1,1,-1,-2,-2,2,2};

    int solve(int x , int y , int count,int n,vector<vector<vector<int>>>&dp){
        if(!isSafe(x,y)){
            return 0;
        }
        if(count==n){
            return 1;
        }
        if(dp[x][y][count]!=-1) return dp[x][y][count];

        long long ans = 0;
        for (int i = 0; i < 8; i++) {
        int nx = x + vx[i];
        int ny = y + vy[i];     
        int result = solve(nx, ny, count + 1, n, dp);
        ans = (ans + result) % MOD;
        
        }
        return dp[x][y][count] = (int)ans;;
    }
    int knightDialer(int n) {
        vector<vector<vector<int>>>dp(4,vector<vector<int>>(3,vector<int>(n+1,-1)));
        long long ans = 0;
        check.resize(4,vector<int>(3));
        check[3][0] = check[3][2] = -1;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(check[i][j]!=-1){
                    long long  result = solve(i,j,1,n,dp);
                     ans = (ans + result)%MOD;
                }
            }
        }
        cout<<ans;
        return (int)ans;
    }
};