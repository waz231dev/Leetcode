class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(low < high){
            int mid = (low + high) >> 1;
            
            if(countLessOrEqual(matrix,mid) < k){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    
    int countLessOrEqual(vector<vector<int>>& matrix,int x){
        int n = matrix.size();
        int c = n - 1;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            while(c >= 0 && matrix[i][c] > x) c--;
            
            count += c+1;
        }
        return count;        
    }
};