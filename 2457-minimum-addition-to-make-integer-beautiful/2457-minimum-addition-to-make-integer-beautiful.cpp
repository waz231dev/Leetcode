class Solution {
    bool isBeautiful(long long n,int target){
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        
        return sum <= target;
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long original = n ,base = 10;
        while(!isBeautiful(n,target)){
            n = (n/base + 1)*base;
            base *= 10;
        }
        
        return n - original;
    }
};