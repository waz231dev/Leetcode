class Solution {
    void reverse(string& s,int i,int j){
        while(i < j){
            swap(s[i++],s[j--]);
        }
    }
public:
    string reverseWords(string s) {
        
        int i = 0;
        while(s[i] == ' ')i++;
        int j = 0;
        for(; i < s.size() ; i++){
            if(s[i] != ' '){
                s[j++] = s[i];
            }else{
                if(s[i-1] != ' ')
                    s[j++] = s[i];
            }
        }
        
        while(s[j-1] == ' ') j--;
        reverse(s,0,j-1);
        int start = 0;
        int end = 0;
        for(int k = 0 ; k < j ; k++){
            while(k < j && s[k] != ' ') k++;
            end = k-1;
            // cout<<s[start]<<s[end];
            reverse(s,start,end);
            start = k+1;
        }
        reverse(s,start,j-1);
        
        s.resize(j);
        return s;
        // string ans = "";
        // for(int k = 0 ; k < j ; k++){
        //     ans += s[k];
        // }
        // return ans;
    }
};