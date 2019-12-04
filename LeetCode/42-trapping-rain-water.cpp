class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> minLevel(height.size(), 0);
        
        int leftMaxSoFar = 0;
        for (int i = 0; i < height.size(); i++) {
            minLevel[i] = leftMaxSoFar;
            leftMaxSoFar = leftMaxSoFar < height[i] ? height[i] : leftMaxSoFar;
        }
        
        int rightMaxSoFar = 0;
        for (int j = height.size() - 1; j >= 0; j--) {
            minLevel[j] = min(minLevel[j], rightMaxSoFar);
            rightMaxSoFar = rightMaxSoFar < height[j] ? height[j] : rightMaxSoFar;
        }
        
        int water = 0;
        for (int k = 0; k < height.size(); k++) {
            if (height[k] < minLevel[k]) {
                water += minLevel[k] - height[k];
            }
        }
        return water;
    }
};