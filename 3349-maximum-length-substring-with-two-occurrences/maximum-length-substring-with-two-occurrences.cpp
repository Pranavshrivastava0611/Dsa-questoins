class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>m;
        int i=0;
        int j =0;
        int n = s.length();
        int ans = 0;
        while(j < n){
            m[s[j]]++;
            while(i <= j && m[s[j]] > 2){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};