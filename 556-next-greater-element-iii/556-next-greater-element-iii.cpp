class Solution {
    void nextPermutation(string& num){
        int n = num.size();
        if(n<2)
            return;
        int ind1 = -1;
        for(int i = n-2 ; i>= 0 ; i--){
            if(num[i]<num[i+1]){
                ind1 = i;
                break;
            }
        }
        // cout<<ind1;
        if(ind1 == -1) return;
        int ind2;
        for(int i = n-1 ; i >= 0 ; i--){
            if(num[i] > num[ind1]){
                ind2 = i;
                break;
            }
        }
        // cout<<ind1<<ind2;
        swap(num[ind1],num[ind2]);
        reverse(num.begin()+ind1+1,num.end());
    }
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        nextPermutation(num);
        long np = stol(num);
        return np>INT_MAX || np == n ? -1 : np;
    }
};