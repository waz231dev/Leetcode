class MyCalendarThree {
    map<int,int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int common = 0;
        int maxCommon = 0;
        for(auto it : mp){
            common += it.second;
            maxCommon = max(maxCommon,common);
        }
        return maxCommon;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */