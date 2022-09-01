class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int gasLeft = 0;
        int deficit = 0;
        
        for(int i = 0 ; i < gas.size() ; i++){
            gasLeft += gas[i]-cost[i];
            if(gasLeft < 0){
                start = i+1;
                deficit += gasLeft;
                gasLeft = 0;
            }
        }
        
        return gasLeft+deficit>=0?start : -1;
    }
};