class Solution {
public:
/*    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // vector<vector<int>> ans(m,vector<int>(n,0));
        queue<vector<int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }
        int del[] = {-1,0,1,0,-1};
        while(!q.empty()){
            vector<int> front = q.front();
            int r = front[0];
            int c = front[1];
            int d = front[2];
            
            q.pop();
            
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + del[i];
                int nc = c + del[i+1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    mat[nr][nc] = d+1;
                    q.push({nr,nc,d+1});
                }
            }
        }
        return mat;
    }
    */
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] != 0){
                    int top = 1e5,left = 1e5;
                    if(i>0) top = mat[i-1][j];
                    if(j>0) left = mat[i][j-1];
                    mat[i][j] = min(top,left)+1;
                }
            }
        }
        
        for(int i = m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(mat[i][j] != 0){
                    int bottom = 1e5,right = 1e5;
                    if(i<m-1) bottom = mat[i+1][j];
                    if(j<n-1) right = mat[i][j+1];
                    mat[i][j] = min(mat[i][j],min(bottom,right)+1);
                }
            }
        }
        return mat;
    }
};