class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int champion = -1 ;
        int size = grid.size();
        for(int i =0;i<size;i++){
            bool check = false;
            for(int j=0;j<size;j++){
                if(i!=j){
                    if(grid[i][j]!=1){
                        check = true;
                        break;
                    }
                }
            }
            if(!check){
                champion = i;
            }
        }
        return champion;
    }
};