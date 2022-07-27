class Solution {
    int helper(vector<int>& temp,int n,int rsum){
        // unordered_map<int,int> presum;
        int maxA = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(temp[i] == rsum){
                sum += temp[i];
                maxA = max(maxA,sum);
            }else{
                sum = 0;
            }
        }
        
        return maxA;
    }
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        int maxA = 0;
        for(int left = 0 ; left < m ; left++){
            
            vector<int> temp(n,0);
            for(int right = left ; right < m ; right++){
                
                for(int i = 0 ; i < n ; i++){
                    
                    temp[i] += a[i][right]-'0';
                }
                
                maxA = max(maxA,helper(temp,n,right-left+1));
            }
        }
        
        return maxA;
    }
};