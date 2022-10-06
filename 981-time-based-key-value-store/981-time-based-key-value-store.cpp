class TimeMap {
    unordered_map<string,vector<pair<int,string>>> hm;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hm[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(hm.find(key) == hm.end()) return "";
        int low = 0;
        int high = hm[key].size();
        while(low < high){
            int mid = low + (high-low)/2;
            if(hm[key][mid].first <= timestamp){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        if(low <= 0 || low > hm[key].size()) return "";
        
        return hm[key][low-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */