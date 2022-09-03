class Solution {
    int digitCount(int num){
        int cnt = 0;
        while(num){
            cnt++;
            num /= 10;
        }
        return cnt;
    }
public:
    void solve(int num,int n,int k,vector<int>& res){
        if(n == 0){
            res.push_back(num);
            return;
        }
        
        for(int i = 0 ; i <= 9 ; i++){
            int ld = num%10;
            if(abs(ld-i) == k){
                solve((num*10+i),n-1,k,res);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i = 1 ; i <= 9 ; i++){
            solve(i,n-1,k,res);
        }
        return res;
    }
};