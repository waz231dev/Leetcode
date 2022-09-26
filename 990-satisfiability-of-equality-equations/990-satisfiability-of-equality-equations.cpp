class Solution {
    void dfs(int node,vector<int> adj[],vector<int>& number,int numAssign,vector<int>& visited){
        visited[node] = 1;
        number[node] = numAssign;
        
        for(auto it : adj[node]){
            if(!visited[it])
                dfs(it,adj,number,numAssign,visited);
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        
        vector<int> adj[26];
        
        for(int i = 0 ; i < equations.size() ; i++){
            if(equations[i][1] == '='){
                adj[equations[i][0]-'a'].push_back(equations[i][3]-'a');
                adj[equations[i][3]-'a'].push_back(equations[i][0]-'a');
            }
        }
        
        vector<int> number(26,0);
        int numAssign = 0;
        vector<int> visited(26,0);
       
        for(int i = 0 ; i < 26 ; i++){
            if(!visited[i]){
                dfs(i,adj,number,numAssign,visited);
            }
            numAssign++;
        }
        
        for(int i = 0 ; i < equations.size() ; i++){
            if(equations[i][1] == '!'){
                if(number[equations[i][0]-'a'] == number[equations[i][3]-'a']) return false;
            }
        }
        
        return true;
        
    }
};