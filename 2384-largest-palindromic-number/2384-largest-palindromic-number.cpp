class Solution {
public:
    string largestPalindromic(string num) {
         vector<int> freq(10,0);
        for(int i = 0 ; i < num.size() ; i++){
          freq[num[i]-'0']++;
        }
        
        string front = "", back = "";
        
        for(int i=9 ; i >= 0; i--){
            if(i == 0 && front.empty()){
                continue;
            }
            
            while(freq[i] > 1){
                front += (i+'0');
                back += (i+'0');
                freq[i] -= 2;
            }
        }



        for(int i = 9; i >= 0; i--){
            
            if(freq[i]){
                front += i+'0';
                break;
            }
        }
        reverse(back.begin(),back.end());
        return front + back;
    }
};