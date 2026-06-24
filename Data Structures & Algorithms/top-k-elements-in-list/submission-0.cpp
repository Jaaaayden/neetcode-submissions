class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for (int num : nums) 
            num_freq[num]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<
        pair<int, int>>> heap;

        for (pair<const int, int>& entry : num_freq)
        {
            heap.push({entry.second, entry.first}); // we need to sort by freq so
            // entry.second must be the first thing
            if (heap.size() > k) { // we never hav e more than k elements in the heap
            // this approach is better than bucket sort with regards to space/dynamically
                heap.pop();
            }
        }

        vector<int> ret;
        for (int i = 0; i < k; i++)
        {
            ret.push_back(heap.top().second);
            heap.pop();
        }
        return ret;
    }
};
