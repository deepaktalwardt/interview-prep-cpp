class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0;
        int p2 = height.size() - 1;
        int largestContainer = 0;
        while (p1 < p2) {
            int vol = (p2 - p1) * min(height[p1], height[p2]);
            largestContainer = vol > largestContainer ? vol : largestContainer;
            if (height[p1] < height[p2]) {
                p1++;
            } else {
                p2--;
            }
        }
        return largestContainer;
    }
};