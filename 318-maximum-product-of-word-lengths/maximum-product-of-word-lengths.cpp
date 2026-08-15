class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<unordered_map<char, bool>> vis(n);

        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                vis[i][c] = true;
            }
        }

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                bool check = false;

                for (char c : words[i]) {
                    if (vis[j].find(c) != vis[j].end()) {
                        check = true;
                        break;
                    }
                }

                if (!check) {
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
                }
            }
        }

        return ans;
    }
};