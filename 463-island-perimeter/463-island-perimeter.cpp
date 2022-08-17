class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int land = 0;
        int dup = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    land++;
                    if(i!=0 && grid[i-1][j] == 1)
                        dup++;
                    if(j!=0 && grid[i][j-1] == 1)
                        dup++;
                }
            }
        }
        
        return land*4 - dup*2;
        
    }
};