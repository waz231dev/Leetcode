class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<vector<int>,vector<vector<int>>, greater<>> pq;
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++){
            pq.push({matrix[i][0],i,0});
        }
        int ans;
        for(int i = 1 ; i <= k ; i++){
            auto top = pq.top();pq.pop();
            ans = top[0];
            int r = top[1];
            int c = top[2];
            
            if(c + 1 < n){
                pq.push({matrix[r][c+1],r,c+1});
            }
        }
        
        return ans;
    }
};