#include <queue>
#include <map>

class Solution {
public:
    struct KeyWithFreq {
        string key;
        int times;
        KeyWithFreq(string a, int b) : key(a), times(b) {};
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int> counts;
        for (string word : words) {
            auto it = counts.find(word);
            if (it != counts.end()) {
                it->second++;
            } else {
                counts[word] = 1;
            }
        }
        
        priority_queue<KeyWithFreq, vector<KeyWithFreq>, function<bool(KeyWithFreq, KeyWithFreq)>>
            min_heap([](const KeyWithFreq& a, const KeyWithFreq& b) {
                if (a.times < b.times) {
                    return true;
                } else if (a.times == b.times) {
                    if (a.key > b.key) {
                        return true;
                    } 
                }
                return false;
            });
        
        auto it = counts.begin();
        while (it != counts.end()) {
            min_heap.emplace(KeyWithFreq(it->first, it->second));
            it++;
        }
        
        vector<string> result;
        
        for (int i = 0; i < k; i++) {
            result.push_back(min_heap.top().key);
            min_heap.pop();
        }
        return result;
    }
};