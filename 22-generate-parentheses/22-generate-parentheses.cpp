class Solution {
    void solve(int c1,int c2,int n,string curr,vector<string>& ans){
        
        if(c1 == n && c2 == n){
            ans.push_back(curr);
            return;
        }
        if(c2>c1) return;
        if(c1 == n){
            solve(c1,c2+1,n,curr+')',ans);
        }else{
            solve(c1+1,c2,n,curr+'(',ans);
            solve(c1,c2+1,n,curr+')',ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "(";
        solve(1,0,n,curr,ans);
        return ans;
    }
};