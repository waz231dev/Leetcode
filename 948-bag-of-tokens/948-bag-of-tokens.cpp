class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score = 0;
        int i = 0;
        int j = tokens.size()-1;
        
        while(i<=j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                score++;
            }else{
                if(score == 0 || i==j){
                    break;
                }else{
                    score--;
                    power += tokens[j--];
                }
            }
        }
        return score;
    }
};