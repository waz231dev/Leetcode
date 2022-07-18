class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        
        int count = 1;
        int sr = 0,sc = 0,er = n-1,ec = n-1;
        while(count <= n*n){
            
            for(int i = sr,j=sc ; j <= ec && count <= n*n ; j++){
                matrix[i][j] = count++;
            }
            sr++;
            for(int i = sr,j=ec ; i <= er && count <= n*n ; i++){
                matrix[i][j] = count++;
            }
            ec--;
            for(int i = er,j = ec ; j >= sc && count <= n*n ; j--){
                matrix[i][j] = count++;
            }
            er--;
            for(int i = er, j=sc ; i >= sr && count <= n*n ; i--){
                matrix[i][j] = count++;
            }
            sc++;
        }
        
        return matrix;
    }
};