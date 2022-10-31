class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int,int> mp;
        for(int i = 0 ; i < m ; i++){
            mp[i] = matrix[i][0];
        }
        
        for(int j = 1 ; j < n ; j++){
            mp[-j] = matrix[0][j];
        }
        
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[i][j] != mp[i-j]) return false;
            }
        }
        
        return true;
    }
};