class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if (n <= 10) return {};

        unordered_map<int, int> mp;
        vector<string> ans;

        auto getCode = [](char c) {
            if (c == 'A') return 0;
            if (c == 'C') return 1;
            if (c == 'G') return 2;
            return 3; // T
        };

        int code = 0;

        // First 10 characters
        for (int i = 0; i < 10; i++) {
            code = (code << 2) | getCode(s[i]);
        }

        mp[code]++;

        // Sliding window
        for (int i = 10; i < n; i++) {

            // Remove the oldest 2 bits
            code &= (1 << 18) - 1;

            // Add the new character
            code = (code << 2) | getCode(s[i]);

            mp[code]++;

            if (mp[code] == 2) {
                ans.push_back(s.substr(i - 9, 10));
            }
        }

        return ans;
    }
};