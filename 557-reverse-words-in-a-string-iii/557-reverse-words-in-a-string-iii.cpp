class Solution {
    void reverse(string& str,int s,int e){
        while(s<e){
            swap(str[s++],str[e--]);
        }
        // cout<<str<<endl;
    }
public:
    string reverseWords(string s) {
        
        for(int i = 0 ; i < s.size() ;i++){
            int start = i;
            while(i < s.size() and s[i] != ' '){
                i++;
            }
            int end = i-1;
            reverse(s,start,end);
        }
        return s;
    }
};