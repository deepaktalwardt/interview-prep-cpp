// Two heaps based solution. Doesn't run very fast
// Still need to solve it using divide and conquer

#include <queue>
class Solution {
public:
    double distance_squared(vector<int> a) {
        return a[0]*a[0] + a[1]*a[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue <vector<int>, vector<vector<int>>, function <bool(vector<int>, vector<int>)> > 
            max_heap([](vector<int> a, vector<int> b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
        max_heap.emplace(points[0]);
        for (int i = 1; i < points.size(); i++) {
            if (max_heap.size() < K) {
                max_heap.emplace(points[i]);
            } else {
                if (distance_squared(points[i]) < distance_squared(max_heap.top())) {
                    max_heap.pop();
                    max_heap.emplace(points[i]);
                }
            }
        }
        vector<vector<int>> result = {};
        while (!empty(max_heap)) {
            result.push_back(max_heap.top());
            max_heap.pop();
        }
        return {rbegin(result), rend(result)};
    }
};