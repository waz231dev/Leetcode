class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string res = "";
        vector<string> rowString(numRows,"");
        
        int row = 0; int inc = 1;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            rowString[row].push_back(s[i]);
            // cout<<rowString[row]<<endl;
            if(row == 0) inc = 1;
            else if(row == numRows-1) inc = -1;
            
            row += inc;
        }
        
        for(int i = 0 ; i < numRows ; i++){
            // cout<<rowString[i]<<endl;
            res += rowString[i];
        }
        return res;
    }
};