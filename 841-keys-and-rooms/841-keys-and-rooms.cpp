class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int src,vector<int>& vis,int& count){
        vis[src] = true;
        count++;
        for(auto adj : rooms[src]){
            if(!vis[adj]){
                dfs(rooms,adj,vis,count);
            }
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        int count = 0;
        dfs(rooms,0,vis,count);
        // for(int i = 0 ; i < n ; i++){
        //     if(!vis[i])
        //         return false;
        // }
        
        return count == n;
    }
};