class Solution {
    int removeSubs(string& s,char a,char b){
        stack<char> st;
        int cnt = 0;
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(!st.empty() && s[i] == a && st.top() == b){
                st.pop();
                cnt++;
            }else{
                st.push(s[i]);
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        s = res;
        return cnt;
    }
public:
    int maximumGain(string s, int x, int y) {
        
        int xscore,yscore;
        if(x>y){
            xscore = removeSubs(s,'a','b');
            yscore = removeSubs(s,'b','a');
        }else{
            yscore = removeSubs(s,'b','a');
            xscore = removeSubs(s,'a','b');
        }
        
        return xscore*x + yscore*y;
    }
};