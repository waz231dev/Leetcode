class Solution {
    
    bool solve(int i, int j,vector<vector<char>>& board,string word,int k,vector<vector<int>>& vis){
        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j] != word[k] || vis[i][j]){
            return false;
        }
        
        if(k == word.size()-1) return true;
        
        vis[i][j] = 1;
        
        int del[] = {-1,0,1,0,-1};
        for(int it = 0 ; it < 4 ; it++){
            if(solve(i+del[it],j+del[it+1],board,word,k+1,vis)) return true;
        }
        
        vis[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                vector<vector<int>> vis(board.size(),vector<int>(board[0].size()));        
                if(solve(i,j,board,word,0,vis)) return true;
            }
        }
        
        return false;
    }
};