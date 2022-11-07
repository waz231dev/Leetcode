class Solution {
public:
    int maximum69Number (int num) {
//         string s = to_string(num);
//         for(int i = 0 ; i < s.size() ; i++){
//             if(s[i] == '6'){
//                 s[i] = '9';
//                 break;
//             }
//         }
        
//         return stoi(s);
        
        int temp = num;
        int idx = -1;
        int i = 0;
        while(temp){
            if(temp%10 == 6) idx = i;
            temp /= 10;
            i++;
        }
        
        if(idx == -1) return num;
        return num + 3*(pow(10,idx));
    }
};