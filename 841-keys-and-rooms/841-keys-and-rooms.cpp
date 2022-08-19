class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int src,vector<int>& vis){
        vis[src] = true;
        
        for(auto adj : rooms[src]){
            if(!vis[adj]){
                dfs(rooms,adj,vis);
            }
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        
        dfs(rooms,0,vis);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i])
                return false;
        }
        
        return true;
    }
};