class TimeMap {
public:
    // m
    // alice [ {1,happy} , {3 sad} ];
    map<string,vector<pair<int,string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        // if key doesnt exist
        if(m.find(key) == m.end()){
            return "";
        }

        int start = 0;
        int end = m[key].size() - 1;
        string res = "";

        while(start<=end){
            int mid = start + (end-start) /2;
            if(m[key][mid].first <= timestamp){
                res = m[key][mid].second;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return res;
    }
};
