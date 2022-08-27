class Solution {
    int maxSum(vector<int>& arr,int k){
        
        int n = arr.size();
        int maxim = INT_MIN;
        set<int> s;
        s.insert(0);
        int currSum = 0;
        for(int x : arr){
            currSum += x;
            
            auto it = s.lower_bound(currSum-k);
            if(it != s.end()){
                maxim = max(maxim,currSum - *it);
            }
            s.insert(currSum);
        }
        
        return maxim;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = -1e6;
        for(int c1 = 0 ; c1 < n ; c1++){
            vector<int> arr(m);
            for(int c2 = c1 ; c2 < n ; c2++){
                for(int row = 0 ; row < m ; row++){
                    arr[row] += matrix[row][c2];
                }
                
                ans = max(ans,maxSum(arr,k));
            }
        }
        return ans;
    }
};