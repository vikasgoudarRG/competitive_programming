// https://leetcode.com/problems/snapshot-array/submissions/1655752439/?envType=study-plan-v2&envId=binary-search

class SnapshotArray {
private:
    int _snap_id = 0;
    vector<vector<pair<int, int>>> _history;

public:
    SnapshotArray(int length) : _history(length, vector<pair<int, int>>(1, {0,0})){
    }
    
    void set(int index, int val) {
        _history[index].push_back({_snap_id, val});
    }
    
    int snap() {
        return _snap_id++;
    }
    
    int get(int index, int snap_id) {
        int n = _history[index].size();
        int left = 0;
        int right = n;

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (_history[index][middle].first <= snap_id) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }
        --left;
        
        // output should be guaranteed the way the question is posed
        return _history[index][left].second;


    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
