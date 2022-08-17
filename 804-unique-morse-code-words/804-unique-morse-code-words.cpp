class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        
        for(auto word : words){
            string str = "";
            for(char c : word){
                str += code[c-'a'];
            }
            s.insert(str);
        }
        
        return s.size();
    }
};