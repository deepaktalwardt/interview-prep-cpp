class Solution {
public:
    struct KeyWithFreq {
        int key;
        int times;
        KeyWithFreq(int a, int b) : key(a), times(b) {};
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> counts;
        
        for (int a : nums) {
            auto it = counts.find(a);
            if (it != counts.end()) {
                it->second++;
            } else {
                counts[a] = 1;
            }
        }
        
        priority_queue<KeyWithFreq, vector<KeyWithFreq>, function<bool(KeyWithFreq, KeyWithFreq)>> 
            min_heap([](const KeyWithFreq &a, const KeyWithFreq &b) { return a.times <= b.times; });
        
        auto it = counts.begin();
        while (it != counts.end()) {
            min_heap.emplace(KeyWithFreq(it->first, it->second));
            it++;
        }
        
        vector<int> result;
        
        for (int i = 0; i < k; i++) {
            result.push_back(min_heap.top().key);
            min_heap.pop();
        }
        return result;
    }

};