class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int res = 0;
        unordered_map<int,int> counter;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                int curr = 0;
                counter = {{0,1}};
                for(int k = 0 ; k < m ; k++){
                    curr += matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);
                    res += counter[curr-target];
                    counter[curr]++;
                }
            }
        }
        return res;
    }
};