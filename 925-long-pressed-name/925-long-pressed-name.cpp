class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j=0; 
        for(int i = 0; i < typed.size() ; i++){
            if(name[j] == typed[i]){
                j++;
            }else if(i>0 && typed[i] == typed[i-1]){
                continue;
            }else{
                return false;
            }
        }
        return j == name.size();
    }
};