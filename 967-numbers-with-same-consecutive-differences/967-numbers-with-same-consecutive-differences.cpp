class Solution {
public:
    void solve(int num,int n,int k,vector<int>& res){
        if(n == 0){
            if(res.empty() or res[res.size()-1] != num){
                res.push_back(num);
            }
            return;
        }
        
        // for(int i = 0 ; i <= 9 ; i++){
            int ld = num%10;
            if(ld-k>=0){
                solve((num*10)+(ld-k),n-1,k,res);
            }
            
            if(ld+k<=9){
                solve((num*10)+(ld+k),n-1,k,res);
            }
        // }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i = 1 ; i <= 9 ; i++){
            solve(i,n-1,k,res);
        }
        return res;
    }
};