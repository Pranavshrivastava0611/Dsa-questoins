class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
       for(int i=0;i<edges.size();i++){
           int u = edges[i][0];
           int v = edges[i][1];
           adj[u].push_back({v,edges[i][2]});
       }
       vector<int>dist(n+1,INT_MAX);
       dist[k] = 0;
       set<pair<int,int>>st;
       st.insert({0,k});
      
        while(!st.empty()){
            auto top = st.begin();
            int node = top->second;
            int current_weight = top->first;
            st.erase(st.begin());
            
            for(auto neighbour : adj[node]){
                int n_node = neighbour.first;
                int weight = neighbour.second;
                
                int distance = weight + current_weight;
                if(dist[n_node]==INT_MAX || dist[n_node] > distance){
                    if(st.find({dist[n_node],n_node})!=st.end()){
                        st.erase({dist[n_node],n_node});
                    }
                    st.insert({distance,n_node});
                    dist[n_node] = distance;                }
            }
        }
        int a = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }else{
                a = max(a,dist[i]);
            }
        }
        return a;
    }
};