class MyCalendar {
    unordered_map<int,int> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : bookings){
            if(!(start>=it.second) && !(it.first >= end))
                return false;
        }
        bookings[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */