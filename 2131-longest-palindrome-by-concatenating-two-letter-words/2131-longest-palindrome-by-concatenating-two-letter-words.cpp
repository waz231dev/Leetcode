class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> freq(26,vector<int>(26,0));
        int ans = 0;
        for(string word : words){
            int first = word[0]-'a';
            int sec = word[1]-'a';
            if(freq[sec][first] > 0){
                ans += 4;
                freq[sec][first]--;
            }else{
                freq[first][sec]++;
            }
        }
        
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i][i] > 0){
                ans += 2;
                break;
            }
        }
        
        return ans;
    }
};