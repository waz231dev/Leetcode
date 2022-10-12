class Solution {
    int lcs(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<int> prev(m+1),curr(m+1);
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        
        return (l1+l2)-2*lcs(word1,word2);
    }
};