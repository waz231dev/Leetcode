class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int i,vector<int>& vis,int n){
        
        vis[i] = 1;
        for(int it = 0 ; it < n ; it++){
            if(vis[it] == 0 && i != it && isConnected[i][it] == 1){
                dfs(isConnected,it,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0){
                dfs(isConnected,i,vis,n);
                cnt++;
            }
        }
        
        return cnt;
        
    }
};