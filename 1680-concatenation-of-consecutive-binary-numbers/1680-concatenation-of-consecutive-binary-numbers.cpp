class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1000000007;
        long ans = 1;
        for(int i = 2 ; i <= n ; i++){
            int numOfBits = (int)log2(i)+1;
            ans = ((ans*(1<<numOfBits))%mod+i)%mod;
        }
        return (int)ans;
    }
};