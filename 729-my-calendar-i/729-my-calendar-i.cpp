class MyCalendar {
    map<int,int> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto slot = bookings.upper_bound(start);
        if(slot != bookings.end() and slot->second < end)
            return false;
        bookings[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */