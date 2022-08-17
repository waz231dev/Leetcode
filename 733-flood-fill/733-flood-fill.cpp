class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& image,int r,int c,int color,int start){
        image[r][c] = color;
        
        int d[] = {-1,0,1,0,-1};
        for(int i = 0 ; i < 4 ; i++){
            int dx = r + d[i];
            int dy = c + d[i+1];
            
            if(dx < 0 || dy < 0 || dx >= m || dy >= n){
                continue;
            }
            
            if(image[dx][dy] == start){
                dfs(image,dx,dy,color,start);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        m = image.size();
        n = image[0].size();
        if(image[sr][sc] == color)
            return image;
        
        dfs(image,sr,sc,color,image[sr][sc]);
        
        return image;
    }
};