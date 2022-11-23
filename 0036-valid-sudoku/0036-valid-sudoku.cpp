class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        for(int i=0;i<9;i++){
            vector<int> check(10,0);
            for(int j=0;j<9;j++){
                int num = board[i][j]-'0';
                if(num>=1 && num<=9){
                    check[num]++;
                    if(check[num]>1)
                        return false;
                }
                
            }
        }
        
        for(int i=0;i<9;i++){
            vector<int> check(10,0);
            for(int j=0;j<9;j++){
                int num = board[j][i]-'0';
                if(num>=1 && num<=9){
                    check[num]++;
                    if(check[num]>1)
                        return false;
                }
                
            }
        }
        for(int k=0;k<9;k++){
            vector<int> check(10,0);
            for(int i=(k/3)*3;i<(k/3)*3+3;i++){
                for(int j=(k*3)%9;j<(k*3)%9+3;j++){
                    int num = board[i][j]-'0';
                    if(num>=1 && num<=9){
                        check[num]++;
                        if(check[num]>1)
                            return false;
                    }
                }    
            }
        }
        return true;
    }
};