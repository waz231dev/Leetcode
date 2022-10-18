class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string asf = countAndSay(n-1);
        string ans = "";
        for(int i = 0 ; i < asf.size() ;){
            int count = 1;
            int j;
            for(j = i+1 ; j < asf.size() && asf[i] == asf[j] ; j++) count++;
            ans += to_string(count);
            ans += asf[i];
            i = j;
        }
        
        return ans;
    }
};