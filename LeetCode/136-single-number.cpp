// Hashset method
// O(n) time | O(n) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            if (s.find(curr) == s.end())
            {
                s.insert(curr);
            }
            else
            {
                s.erase(curr);
            }
        }
        return *(s.begin());
    }
};


// Math method 
// O(n) time | O(n) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        int actualSum = 0;
        int doubleSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            actualSum += curr;
            
            if (s.find(curr) == s.end())
            {
                s.insert(curr);
                doubleSum += curr + curr;
            }
        }
        return doubleSum - actualSum;
    }
};

// Bit manipulation
// O(n) time | O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }
}; 