class Solution {
public:
    string smallestPalindrome(string s) {
        int size = s.length();
        if(size==1) return s;
        bool check_odd;
        if(size&1){
            check_odd = true;
        }
        map<char,int>str;
        for(auto i : s){
            str[i]++;
        }
        string ans;
        ans.resize(size);
        int first = 0;
        int last = size-1;
        while(!str.empty() && first <=last){
            auto top = str.begin();
            while(top->second>1 && first <= last){
                ans[first] = top->first;
                ans[last] = top->first;
                first++;
                last--;
                str[top->first] = str[top->first] - 2;
            }
            if(top->second==1){
                ans[size/2] = top->first;
            }
            str.erase(str.begin());
        }
        return ans;
    }
};