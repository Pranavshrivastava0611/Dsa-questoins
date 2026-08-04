class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<vector<int>> check;
    vector<int> vx = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> vy = {1, -1, 1, -1, -2, 2, -2, 2};

    bool isSafe(int x, int y) {
        return x >= 0 && x < 4 && y >= 0 && y < 3 && check[x][y] != -1;
    }

    int solve(int x, int y, int count, int n,
              vector<vector<vector<int>>>& dp) {

        if (!isSafe(x, y))
            return 0;

        if (count == n)
            return 1;

        if (dp[x][y][count] != -1)
            return dp[x][y][count];

        long long ans = 0;

        for (int i = 0; i < 8; i++) {
            int nx = x + vx[i];
            int ny = y + vy[i];

            ans = (ans + solve(nx, ny, count + 1, n, dp)) % MOD;
        }

        return dp[x][y][count] = (int)ans;
    }

    int knightDialer(int n) {
        vector<vector<vector<int>>> dp(
            4, vector<vector<int>>(3, vector<int>(n + 1, -1)));

        check.assign(4, vector<int>(3, 0));
        check[3][0] = -1;
        check[3][2] = -1;

        long long ans = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (check[i][j] != -1) {
                    ans = (ans + solve(i, j, 1, n, dp)) % MOD;
                }
            }
        }

        return (int)ans;
    }
};