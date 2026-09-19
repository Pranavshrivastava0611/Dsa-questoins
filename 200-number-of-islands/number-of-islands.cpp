class Solution {
public:
    bool issafe(int nx,int ny,int x , int y){
        return nx >=0 && nx < x && ny >=0 && ny < y;
    }
    vector<int>vx = {-1,1,0,0};
    vector<int>vy = {0,0,-1,1};
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    vis[i][j] = true;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto top = q.front();
                        q.pop();
                        int x = top.first;
                        int y = top.second;
                        for(int i=0;i<4;i++){
                            int nx = x + vx[i];
                            int ny = y + vy[i];
                            if(issafe(nx,ny,m,n) && !vis[nx][ny] && grid[nx][ny]=='1'){
                                vis[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        cout<<count;
        return count;
    }
};