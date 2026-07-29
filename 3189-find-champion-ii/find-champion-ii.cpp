class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto &eg : edges){
            indegree[eg[1]]++;
        }
        vector<int>checkk;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                checkk.push_back(i);
            }
        }
        if(checkk.size() >1 ){
            return -1;
        }
        return checkk[0];
    }
};