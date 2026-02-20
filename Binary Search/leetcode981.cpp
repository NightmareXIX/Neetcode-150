#include <bits/stdc++.h>
using namespace std; 

class TimeMap {
private: 
    map<string, vector<pair<int, string>>> mp; 
public:
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value}); 
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(mp[key].begin(), mp[key].end(), pair<int, string>{timestamp + 1, ""}); 
        if (it == mp[key].begin()) 
            return ""; 
        else {
            it--; 
            return it->second; 
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */