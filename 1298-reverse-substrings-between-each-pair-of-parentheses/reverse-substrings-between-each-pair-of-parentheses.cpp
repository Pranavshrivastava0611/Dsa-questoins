class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        int len = s.length();
        for(int i=0;i<len;i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }else{
                string str = "";
                while(!st.empty() && st.top()!='('){
                    str.push_back(st.top());
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(auto i : str){
                    st.push(i);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};