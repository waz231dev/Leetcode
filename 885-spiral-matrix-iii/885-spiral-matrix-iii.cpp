class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> mat;
        int count = rows * cols;
        int step = 1;
        int x = rStart , y = cStart;
        while(count){
            
            for(int i = 0 ; i < step && count; i++){
                if(x>=0 && x<rows && y>=0 && y<cols){
                    mat.push_back({x,y});
                    count--;
                }
                y++;
            }
            
            for(int i = 0 ; i < step && count; i++){
                if(x>=0 && x<rows && y>=0 && y<cols){
                    mat.push_back({x,y});
                    count--;
                }
                x++;
            }
            step++;
            for(int i = 0 ; i < step && count; i++){
                if(x>=0 && x<rows && y>=0 && y<cols){
                    mat.push_back({x,y});
                    count--;
                }
                y--;
            }
            
            for(int i = 0 ; i < step && count; i++){
                if(x>=0 && x<rows && y>=0 && y<cols){
                    mat.push_back({x,y});
                    count--;
                }
                x--;
            }
            step++;
        }
        return mat;
    }
};