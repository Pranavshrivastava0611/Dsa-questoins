class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n <= 10) return {};
        string str = "";
        for(int i=0;i<10;i++){
            str = str + s[i];
        }
        unordered_map<string,int>store;
        store[str]++;
        int i=1;
        int j=10;
        while(j<n){
            str.erase(str.begin());
            str.push_back(s[j]);
            store[str]++;
            j++;
        }
        vector<string>ans;
        for(auto p : store){
            if(p.second >= 2){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};