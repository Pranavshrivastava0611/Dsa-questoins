class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto i : knowledge){
            mp[i[0]] = i[1];
        }
        int len = s.length();
        string ans = "";
        bool isOpen = false;
        int last = -1;
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                isOpen = true;
                last = i;
            }else if(s[i]==')'){
                int idx = last+1;
                string str = "";
                for(int j = idx;j<i;j++){
                    str.push_back(s[j]);
                }
                 if(mp.find(str)==mp.end()){
                        ans.push_back('?');
                    }else{
                        ans += mp[str];
                    }
                    last = -1;
                    isOpen = false;
            }else{
                if(!isOpen){
                    ans.push_back(s[i]);
                }
            }
        }
        return ans; 
    }
};