// https://leetcode.com/problems/time-based-key-value-store/submissions/1655476481/?envType=study-plan-v2&envId=binary-search

// exploting the statement: timestamps of set are strictly increasing
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        unordered_map<string, vector<pair<int, string>>>::iterator it = data.find(key);
        if (it == data.end()) {
            return "";
        }
        int left = 0;
        int right = it->second.size();

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (it->second[middle].first <= timestamp) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }
        --left;
        if (left >= 0) {
            return it->second[left].second;
        }
        else {
            return "";
        }
    }
};

/*
class TimeMap {
private:
    unordered_map<string, map<int, string>> data;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        data[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        unordered_map<string, map<int, string>>::iterator it_outer = data.find(key);
        if (it_outer == data.end()) {
            return "";
        }
        map<int, string>::iterator it_inner = it_outer->second.upper_bound(timestamp);
        if (it_inner == it_outer->second.begin()) {
            return "";
        }
        else {
            --it_inner;
            return it_inner->second;
        }
    }
};
*/

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
