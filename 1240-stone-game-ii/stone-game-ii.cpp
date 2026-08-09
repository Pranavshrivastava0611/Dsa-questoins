class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    vector<int> prefix;

    int solve(int i, int m, int turn) {
        if (i >= n)
            return 0;

        if (dp[i][m][turn] != -1)
            return dp[i][m][turn];

        int ans;

        if (turn == 0) { 
            ans = 0;

            for (int x = 1; x <= 2 * m && i + x <= n; x++) {
                int taken = prefix[i + x] - prefix[i];

                ans = max(ans,
                    taken + solve(i + x, max(m, x), 1)
                );
            }
        }
        else {
            ans = INT_MAX;

            for (int x = 1; x <= 2 * m && i + x <= n; x++) {
                ans = min(ans,
                    solve(i + x, max(m, x), 0)
                );
            }
        }

        return dp[i][m][turn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + piles[i];

        dp.assign(n, vector<vector<int>>(n + 1,
            vector<int>(2, -1)));

        return solve(0, 1, 0);
    }
};