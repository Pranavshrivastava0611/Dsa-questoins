class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        for(int i=0;i<invo.size();i++){
            adj[invo[i][0]].push_back(invo[i][1]);
            indegree[invo[i][1]]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(i);
        }
        vector<bool>flag(n,false);
        queue<int>q;
        unordered_map<int,bool>vis;
        q.push(k);
        vis[k] = true;
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            flag[top] = true;

            for(auto nei : adj[top]){
                if(vis.find(nei)==vis.end()){
                    q.push(nei);
                    vis[nei] = true;
                }
            }
        }
        vector<int>ans2;
        for(int i=0;i<n;i++){
            if(!flag[i]){
                for(auto nei : adj[i]){
                    if(flag[nei]){
                        return ans;
                    }
                }
                ans2.push_back(i);
            }
        }
        for(auto i : flag){
            cout<<i<<" ";
        }
        return ans2;
    }
};