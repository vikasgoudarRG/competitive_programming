class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // return heap(nums, k);
        return
    }

    // Heap
    // Time Complexity O(n + nlogk)
    // Space Complexity O(n + k) 
    vector<int> heap(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (int num: nums) {
            umap[num]++;
        }

        auto comp = [&umap](int a, int b) {
            return umap[a] > umap[b];
        };

        priority_queue<int, vector<int>, decltype(comp)> heap(comp);

        // O(n * logk)
        for (pair<int, int> p: umap) {
            heap.push(p.first);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        // O(k * logk)
        vector<int> ans(k);
        for (int i = k - 1; i > -1; --i) {
            ans[i] = heap.top();
            heap.pop();
        }

        return ans;
    }
}