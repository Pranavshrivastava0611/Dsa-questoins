class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        string ans = "";
        int len = s.length();
        for(int i=0;i<len;i++){
            if(st.empty() || abs((st.top()-s[i]))!=32){
                st.push(s[i]);
                ans.push_back(s[i]);
            }else if(abs((st.top()-s[i]))==32){
                st.pop();
                ans.pop_back();
            }
        }
        return ans;
    }
};