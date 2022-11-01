class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans;
        for(int j = 0 ; j < n ; j++){
            int curr = j;
            int next = -1;
            for(int i = 0 ; i < m ; i++){
                next = curr + grid[i][curr];
                
                if(next < 0 || next >= n || grid[i][curr] != grid[i][next]){
                    curr = -1;
                    break;
                }
                
                curr = next;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};