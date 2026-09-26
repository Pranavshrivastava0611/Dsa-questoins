class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        unordered_map<string,bool>mp;
        unordered_map<string,bool>vis;
        if(beginWord==endWord) return 0;
        for(auto i : wordList){
            mp[i] = true;
        }
        if(mp.find(endWord)==mp.end()) return 0;
        q.push(beginWord);
        vis[beginWord] = true;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int i=0;i<size;i++){
                auto top = q.front();
                q.pop();
                if(top==endWord){
                    return ans;
                }
                int len = top.length();
                for(int i=0;i<len;i++){
                   string str2 = top;
                   int idx = str2[i]-'a';
                    for(int j=0;j<26;j++){
                        if(j!=idx){
                        str2[i] = 'a' + j;
                        if(mp.find(str2)!=mp.end() && !vis[str2]){
                            q.push(str2);
                            vis[str2] = true;
                        }
                        }
                    }
                }
            }
        }
        return 0;
    }
};