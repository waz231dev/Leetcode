class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n+1);
        
        for(auto shift : shifts){
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];
            if(dir == 1){
                arr[start]++;
                arr[end+1]--;
            }else{
                arr[start]--;
                arr[end+1]++;
            }
        }
        
        int diff = 0 ;
        for(int i = 0 ; i < n ; i++){
            s[i] = (((s[i]-'a' + (diff += arr[i]))%26 + 26)%26 + 'a');
        }
        return s;
    }
};