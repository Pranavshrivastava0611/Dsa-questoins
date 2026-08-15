class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> ws;
        ws.reserve(n);

        for (string &word : words) {
            int mask = 0;
            for (char c : word) {
                int index = c - 'a';
                mask |= (1 << index);
            }

            ws.push_back(mask);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ws[i] & ws[j]) continue;

                ans = max(ans, (int) (words[i].size() * words[j].size()));
            }
        }

        return ans;
    }
};